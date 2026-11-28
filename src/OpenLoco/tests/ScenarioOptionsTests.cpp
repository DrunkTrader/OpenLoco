#include <OpenLoco/EditorController.h>
#include <OpenLoco/Scenario/ScenarioOptions.h>
#include <gtest/gtest.h>

using namespace OpenLoco;

TEST(ScenarioOptionsTest, CompleteScenarioHasNullEditorStep)
{
    Scenario::Options options{};
    options.editorStep = EditorController::Step::null;

    EXPECT_TRUE(Scenario::isCompleteScenario(options));
}

TEST(ScenarioOptionsTest, IncompleteScenarioHasEditorStep)
{
    Scenario::Options options{};

    for (const auto step : { EditorController::Step::objectSelection,
                             EditorController::Step::landscapeEditor,
                             EditorController::Step::scenarioOptions,
                             EditorController::Step::saveScenario })
    {
        options.editorStep = step;
        EXPECT_FALSE(Scenario::isCompleteScenario(options));
    }
}
