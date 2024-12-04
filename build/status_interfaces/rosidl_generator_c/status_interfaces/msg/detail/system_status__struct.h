﻿// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from status_interfaces:msg/SystemStatus.idl
// generated code does not contain a copyright notice

#ifndef STATUS_INTERFACES__MSG__DETAIL__SYSTEM_STATUS__STRUCT_H_
#define STATUS_INTERFACES__MSG__DETAIL__SYSTEM_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'host_name'
#include "rosidl_runtime_c/string.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in msg/SystemStatus in the package status_interfaces.
/**
  * System
 */
typedef struct status_interfaces__msg__SystemStatus
{
  /// 主机名字
  rosidl_runtime_c__String host_name;
  /// cpu使用率
  float cpu_percent;
  /// 内存使用率
  float memory_percent;
  /// 内存大小
  float memory_total;
  /// 剩余内存、
  double memory_available;
  /// 网络发送数据总量
  double net_sent;
  /// 数据接受总量
  double net_recv;
  /// 记录时间戳
  builtin_interfaces__msg__Time stamp;
} status_interfaces__msg__SystemStatus;

// Struct for a sequence of status_interfaces__msg__SystemStatus.
typedef struct status_interfaces__msg__SystemStatus__Sequence
{
  status_interfaces__msg__SystemStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} status_interfaces__msg__SystemStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STATUS_INTERFACES__MSG__DETAIL__SYSTEM_STATUS__STRUCT_H_
