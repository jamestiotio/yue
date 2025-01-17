const {clang, targetCpu, targetOs} = require('./common')

// The version of nuget WebView2 package.
const webview2Version = '1.0.1722.45'

// The versions of language bindings to test against.
const nodeVersions = [
  '16.20.2',
  '18.17.1',
  '20.5.1',
]
const electronVersions = [
  '24.8.1',
  '25.7.0',
  '26.1.0',
]
const luaVersions = [
  '5.3.6',
  '5.4.3',
  '5.1.5',
]

// The version of gn.
const gnVersion = '0.10.0'

// The common build configurations.
const gnConfig = [
  `is_clang=${clang}`,
  `target_cpu="${targetCpu}"`,
  `lua_version="v${luaVersions[0]}"`,
  'fatal_linker_warnings=false',
]
if (targetOs == 'win') {
  gnConfig.push(`webview2_version="${webview2Version}"`)
}

// The build configuration for sysroot.
const gnSysrootConfig = [
  'use_sysroot=true',
  'debian_platform="sid"',
  'target_sysroot_dir="//third_party/"',
]

module.exports = {
  webview2Version,
  nodeVersions,
  electronVersions,
  luaVersions,
  gnVersion,
  gnConfig,
  gnSysrootConfig,
}
