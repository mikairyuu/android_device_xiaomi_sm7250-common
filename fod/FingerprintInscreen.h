/*
 * Copyright (C) 2019-2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H
#define VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H

#include <vendor/lineage/biometrics/fingerprint/inscreen/1.1/IFingerprintInscreen.h>
#include <vendor/xiaomi/hardware/fingerprintextension/1.0/IXiaomiFingerprint.h>

namespace vendor {
namespace lineage {
namespace biometrics {
namespace fingerprint {
namespace inscreen {
namespace V1_1 {
namespace implementation {

using ::android::sp;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::vendor::xiaomi::hardware::fingerprintextension::V1_0::IXiaomiFingerprint;

class FingerprintInscreen : public IFingerprintInscreen {
  public:
    FingerprintInscreen();

    Return<void> onStartEnroll() override;
    Return<void> onFinishEnroll() override;
    Return<void> onPress() override;
    Return<void> onRelease() override;
    Return<void> onShowFODView() override;
    Return<void> onHideFODView() override;
    Return<bool> handleAcquired(int32_t acquiredInfo, int32_t vendorCode) override;
    Return<bool> handleError(int32_t error, int32_t vendorCode) override;
    Return<void> setLongPressEnabled(bool enabled) override;
    Return<int32_t> getDimAmount(int32_t cur_brightness) override;
    Return<bool> shouldBoostBrightness() override;
    Return<void> setCallback(const sp<V1_0::IFingerprintInscreenCallback>& callback) override;
    Return<int32_t> getPositionX() override;
    Return<int32_t> getPositionY() override;
    Return<int32_t> getSize() override;
    Return<bool> shouldEnableDimlayer() override;

  private:
    sp<IXiaomiFingerprint> mXiaomiFingerprintService;
};

}  // namespace implementation
}  // namespace V1_1
}  // namespace inscreen
}  // namespace fingerprint
}  // namespace biometrics
}  // namespace lineage
}  // namespace vendor

#endif  // VENDOR_LINEAGE_BIOMETRICS_FINGERPRINT_INSCREEN_V1_1_FINGERPRINTINSCREEN_H
