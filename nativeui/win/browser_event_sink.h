// Copyright 2018 Cheng Zhao. All rights reserved.
// Copyright 2017 tokikuch.
// Use of this source code is governed by the license that can be found in the
// LICENSE file.

#ifndef NATIVEUI_WIN_BROWSER_EVENT_SINK_H_
#define NATIVEUI_WIN_BROWSER_EVENT_SINK_H_

#include <exdisp.h>
#include <ole2.h>

namespace nu {

class Browser;

class BrowserEventSink : public IDispatch {
 public:
  explicit BrowserEventSink(Browser* browser);
  ~BrowserEventSink();

  // IUnknown
  STDMETHOD(QueryInterface)(REFIID riid, void **ppvObject);
  STDMETHOD_(ULONG, AddRef)();
  STDMETHOD_(ULONG, Release)();

  // IDispatch
  IFACEMETHODIMP GetTypeInfoCount(__RPC__out UINT *pctinfo);
  IFACEMETHODIMP GetTypeInfo(UINT iTInfo,
                             LCID lcid,
                             __RPC__deref_out_opt ITypeInfo **ppTInfo);
  IFACEMETHODIMP GetIDsOfNames(
      __RPC__in REFIID riid,
      __RPC__in_ecount_full(cNames) LPOLESTR *rgszNames,
      __RPC__in_range(0, 16384) UINT cNames,
      LCID lcid,
      __RPC__out_ecount_full(cNames) DISPID *rgDispId);
  IFACEMETHODIMP Invoke(_In_ DISPID dispIdMember,
                        _In_ REFIID riid,
                        _In_ LCID lcid,
                        _In_ WORD wFlags,
                        _In_ DISPPARAMS *pDispParams,
                        _Out_opt_ VARIANT *pVarResult,
                        _Out_opt_ EXCEPINFO *pExcepInfo,
                        _Out_opt_ UINT *puArgErr);

 private:
  ULONG ref_;
  Browser* browser_;
};

}  // namespace nu

#endif  // NATIVEUI_WIN_BROWSER_EVENT_SINK_H_
