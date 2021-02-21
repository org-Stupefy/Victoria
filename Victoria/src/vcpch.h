#pragma once

#include "Victoria/Core/PlatformDetection.h"

#ifdef VC_PLATFORM_WINDOWS
#ifndef NOMINMAX
// See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
#define NOMINMAX
#endif
#endif

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <math.h>
#include <cmath>

#include <iomanip>
#include <chrono>
#include <thread>
#include <mutex>

#include <fstream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Victoria/Core/Base.h"

#include "Victoria/Core/Log.h"
#include "Victoria/Debug/Instrumentor.h"

#ifdef VC_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#ifdef VC_PLATFORM_LINUX
#include <pthread.h>
#include <unistd.h>
#endif
