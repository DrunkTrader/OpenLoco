#include "Scenario/ScenarioOptions.h"

namespace OpenLoco::Scenario
{
    static Options _activeOptions; // 0x009C8714

    bool isCompleteScenario(const Options& options)
    {
        return options.editorStep == EditorController::Step::null;
    }

    Options& getOptions()
    {
        return _activeOptions;
    }
}
