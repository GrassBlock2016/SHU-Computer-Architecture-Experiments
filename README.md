<div align="center">

  <h1>SHU Computer System Architecture Experiments</h1>

   ![Static Badge](https://img.shields.io/badge/C%2B%2B-20%7C23-blue?style=plastic) ![Static Badge](https://img.shields.io/badge/g%2B%2B-13-blue?style=plastic) ![Static Badge](https://img.shields.io/badge/msvc-19-blue?style=plastic) ![Static Badge](https://img.shields.io/badge/cmake-navy?style=plastic&link=https%3A%2F%2Fgithub.com%2Fjamesnulliu%2FPrettyLazy0%2Fblob%2Fmain%2FLICENSE) ![Static Badge](https://img.shields.io/badge/make-navy?style=plastic&link=https%3A%2F%2Fgithub.com%2Fjamesnulliu%2FPrettyLazy0%2Fblob%2Fmain%2FLICENSE) ![Static Badge](https://img.shields.io/badge/ninja-navy?style=plastic&link=https%3A%2F%2Fgithub.com%2Fjamesnulliu%2FPrettyLazy0%2Fblob%2Fmain%2FLICENSE) [![license - MIT](https://img.shields.io/badge/license-MIT-darkgreen?style=plastic)](https://github.com/jamesnulliu/PrettyLazy0/blob/main/LICENSE)

</div>


## Environment Setup

<div align="center">

| OS | Compiler | Build Tools | Make Tools |
|:--:|:--------:|:-----------:|:----------:|
| Linux | g++ >= 13 | cmake >= 3.21 | make |
| Windows | msvc >= 19 | cmake >= 3.21 | ninja |

</div>

Check [Env Setup Guide for Linux](./docs/Env_Setup_Guide_for_Linux.md) or [Env Setup Guide for Windows](./docs/Env_Setup_Guide_for_Windows.md) for details.

## Quick Start

To build the project, run the following commands:

```bash
# On Linux:
bash ./scripts/build.sh Release

# On Windows:
powershell.exe ./scripts/build.ps1 Release
```

You will get target binaries in the "./bin" directory.