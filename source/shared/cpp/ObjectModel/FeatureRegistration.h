#pragma once

#include "pch.h"

namespace AdaptiveSharedNamespace
{
    class SemanticVersion;
    class FeatureRegistration
    {
    public:
        FeatureRegistration(const std::string& adaptiveCardsVersion);

        void AddFeature(const std::string& featureName, const std::string& featureVersion);
        void RemoveFeature(const std::string& featureName);
        SemanticVersion GetAdaptiveCardsVersion() const;
        std::string GetFeatureVersion(const std::string& featureName) const;

    private:
        static constexpr const char* const c_adaptiveCards = "adaptiveCards";
        std::unordered_map<std::string, std::string> m_supportedFeatures;
    };
}
