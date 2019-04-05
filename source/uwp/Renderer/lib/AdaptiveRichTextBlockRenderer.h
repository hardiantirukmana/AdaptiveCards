#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "RichTextBlock.h"

namespace AdaptiveNamespace
{
    class AdaptiveRichTextBlockRenderer
        : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
                                              ABI::AdaptiveNamespace::IAdaptiveElementRenderer,
                                              ABI::AdaptiveNamespace::IAdaptiveElementParser>
    {
        AdaptiveRuntime(AdaptiveRichTextBlockRenderer);

    public:
        HRESULT RuntimeClassInitialize() noexcept;

        IFACEMETHODIMP Render(_In_ ABI::AdaptiveNamespace::IAdaptiveCardElement* cardElement,
                              _In_ ABI::AdaptiveNamespace::IAdaptiveRenderContext* renderContext,
                              _In_ ABI::AdaptiveNamespace::IAdaptiveRenderArgs* renderArgs,
                              _COM_Outptr_ ABI::Windows::UI::Xaml::IUIElement** result) noexcept override;

        IFACEMETHODIMP FromJson(_In_ ABI::Windows::Data::Json::IJsonObject*,
                                _In_ ABI::AdaptiveNamespace::IAdaptiveElementParserRegistration* elementParsers,
                                _In_ ABI::AdaptiveNamespace::IAdaptiveActionParserRegistration* actionParsers,
                                _In_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveWarning*>* adaptiveWarnings,
                                _COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveCardElement** element) noexcept override;

        IFACEMETHODIMP FromJsonWithFeatureRegistration(
            _In_ ABI::Windows::Data::Json::IJsonObject*,
            _In_ ABI::AdaptiveNamespace::IAdaptiveElementParserRegistration* elementParsers,
            _In_ ABI::AdaptiveNamespace::IAdaptiveActionParserRegistration* actionParsers,
            _In_opt_ ABI::AdaptiveNamespace::IAdaptiveFeatureRegistration* featureRegistration,
            _In_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveNamespace::AdaptiveWarning*>* adaptiveWarnings,
            _COM_Outptr_ ABI::AdaptiveNamespace::IAdaptiveCardElement** element) noexcept override;
    };

    ActivatableClass(AdaptiveRichTextBlockRenderer);
}
