// Copyright 2025 Pavel Suprunov
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <cstdint>
#include <driver/i2c_types.h>
#include <vector>

/**
 * @namespace i2c
 */
namespace i2c {

/**
 * @class Device
 * @brief Slave device implementation
 */
class Device {
public:
  using Byte = std::uint8_t;
  using Size = std::size_t;
  using Bytes = std::vector<Byte>;
  using BusHandle = i2c_master_bus_handle_t;
  using DeviceHandle = i2c_master_dev_handle_t;
  using DeviceAddress = std::uint16_t;
  using RegisterAddress = Device::Byte;

public:
  Device(Device::BusHandle busHandle, Device::DeviceAddress deviceAddress);
  ~Device();

public:
  /**
   * Read bytes from device
   * @param registerAddress Register address
   * @param packageSize Package size for read
   * @return Vector of bytes
   */
  Device::Bytes read(Device::RegisterAddress registerAddress, Size packageSize = 1);
  /**
   * Write bytes to device
   * @param registerAddress Register address
   * @param bytes Data package
   */
  void write(Device::RegisterAddress registerAddress, Device::Bytes bytes);

private:
  Device::DeviceHandle m_deviceHandle = nullptr;
};

}// namespace i2c

#include <memory>

using DevicePtr = std::unique_ptr<i2c::Device>;
