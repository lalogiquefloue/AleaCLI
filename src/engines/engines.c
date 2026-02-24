#include "engines.h"
#include <stdio.h>

Engine engines[] = {
    {"mock1", "Mock engine #1.", mock_engine_1, mock_engine_1_setup},
    {"mock2", "Mock engine #2.", mock_engine_2, mock_engine_2_setup}
};

const int ENGINE_COUNT = sizeof(engines) / sizeof(Engine);