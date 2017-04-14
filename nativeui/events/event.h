// Copyright 2017 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_EVENTS_EVENT_H_
#define NATIVEUI_EVENTS_EVENT_H_

#include "nativeui/events/keyboard_codes.h"
#include "nativeui/gfx/geometry/point_f.h"
#include "nativeui/types.h"

namespace nu {

// Supported event types.
enum class EventType {
  Unknown,  // should never be used
  MouseDown,
  MouseUp,
  KeyDown,
  KeyUp,
};

// Base event type.
struct NATIVEUI_EXPORT Event {
  // Event type.
  EventType type;

  // Current keyboard modifiers.
  int modifiers;

  // Time when event was created, starts from when machine was booted.
  uint32_t timestamp;

  // The underlying native event.
  NativeEvent native_event;

 protected:
  // Base Event class should nenver be created by user.
  Event(NativeEvent event, NativeView view);
};

// Mouse click events.
struct NATIVEUI_EXPORT MouseEvent : public Event {
  // Create from the native event.
  MouseEvent(NativeEvent event, NativeView view);

  int button;
  PointF position;
};

}  // namespace nu

#endif  // NATIVEUI_EVENTS_EVENT_H_