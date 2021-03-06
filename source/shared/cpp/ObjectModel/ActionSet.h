#pragma once

#include "pch.h"
#include "BaseActionElement.h"
#include "BaseCardElement.h"
#include "ElementParserRegistration.h"

namespace AdaptiveCards
{
    class ActionSet : public BaseCardElement
    {
        friend class ActionSetParser;

    public:
        ActionSet();
        ActionSet(std::vector<std::shared_ptr<BaseActionElement>>& actions);

        Json::Value SerializeToJsonValue() const override;

        std::vector<std::shared_ptr<BaseActionElement>>& GetActions();
        const std::vector<std::shared_ptr<BaseActionElement>>& GetActions() const;

    private:
        void PopulateKnownPropertiesSet() override;
        std::vector<std::shared_ptr<AdaptiveCards::BaseActionElement>> m_actions;
        ActionsOrientation m_orientation;
    };

    class ActionSetParser : public BaseCardElementParser
    {
    public:
        ActionSetParser() = default;
        ActionSetParser(const ActionSetParser&) = default;
        ActionSetParser(ActionSetParser&&) = default;
        ActionSetParser& operator=(const ActionSetParser&) = default;
        ActionSetParser& operator=(ActionSetParser&&) = default;
        virtual ~ActionSetParser() = default;

        std::shared_ptr<BaseCardElement> Deserialize(ParseContext& context, const Json::Value& root) override;
        std::shared_ptr<BaseCardElement> DeserializeFromString(ParseContext& contexts, const std::string& jsonString) override;
    };
}
