// Copyright 2016 Cheng Zhao. All rights reserved.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_ENTRY_H_
#define NATIVEUI_ENTRY_H_

#include <string>

#include "nativeui/view.h"

namespace nu {

NATIVEUI_EXPORT class Entry : public View{
 public:
  Entry();

  void SetText(const std::string& text);
  std::string GetText() const;

  // Events.
  Signal<void()> on_text_change;
  Signal<void()> on_activate;

 protected:
  ~Entry() override;
};

}  // namespace nu

#endif  // NATIVEUI_ENTRY_H_
