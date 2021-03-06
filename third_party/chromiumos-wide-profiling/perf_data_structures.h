// Copyright 2016 The Chromium OS Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMIUMOS_WIDE_PROFILING_PERF_DATA_STRUCTURES_H_
#define CHROMIUMOS_WIDE_PROFILING_PERF_DATA_STRUCTURES_H_

#include <vector>

#include "chromiumos-wide-profiling/compat/string.h"
#include "third_party/kernel/perf_event.h"

// Data structures that are used by multiple modules.

namespace quipper {

// This is becoming more like a partial struct perf_evsel
struct PerfFileAttr {
  struct perf_event_attr attr;
  string name;
  std::vector<uint64_t> ids;
};

struct PerfUint32Metadata {
  uint32_t type;
  std::vector<uint32_t> data;
};

struct PerfUint64Metadata {
  uint32_t type;
  std::vector<uint64_t> data;
};

struct PerfCPUTopologyMetadata {
  std::vector<string> core_siblings;
  std::vector<string> thread_siblings;
};

struct PerfNodeTopologyMetadata {
  uint32_t id;
  uint64_t total_memory;
  uint64_t free_memory;
  string cpu_list;
};

}  // namespace quipper

#endif  // CHROMIUMOS_WIDE_PROFILING_PERF_DATA_STRUCTURES_H_
