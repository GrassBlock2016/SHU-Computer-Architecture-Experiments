<div align="center">

  <h1>SHU - Computer System Architecture Experiments</h1>

   ![Static Badge](https://img.shields.io/badge/C%2B%2B-23-blue?style=plastic) ![Static Badge](https://img.shields.io/badge/g%2B%2B-13-blue?style=plastic) ![Static Badge](https://img.shields.io/badge/msvc-19-blue?style=plastic) ![Static Badge](https://img.shields.io/badge/cmake-navy?style=plastic&link=https%3A%2F%2Fgithub.com%2Fjamesnulliu%2FPrettyLazy0%2Fblob%2Fmain%2FLICENSE) ![Static Badge](https://img.shields.io/badge/make-navy?style=plastic&link=https%3A%2F%2Fgithub.com%2Fjamesnulliu%2FPrettyLazy0%2Fblob%2Fmain%2FLICENSE) ![Static Badge](https://img.shields.io/badge/ninja-navy?style=plastic&link=https%3A%2F%2Fgithub.com%2Fjamesnulliu%2FPrettyLazy0%2Fblob%2Fmain%2FLICENSE) [![license - MIT](https://img.shields.io/badge/license-MIT-darkgreen?style=plastic)](https://github.com/jamesnulliu/PrettyLazy0/blob/main/LICENSE)

</div>


## Environment Setup

Check [Env Setup Guide for Linux](./docs/Env_Setup_Guide_for_Linux.md) or [Env Setup Guide for Windows](./docs/Env_Setup_Guide_for_Windows.md) for detailed instructions.

<div align="center">

| OS | Compiler | Build Tools | Make Tools |
|:--:|:--------:|:-----------:|:----------:|
| Linux | g++ >= 13 | cmake >= 3.21 | make |
| Windows | msvc >= 19 | cmake >= 3.21 | ninja |

</div>

## Quick Start

Clone the project (ssh is reconmmended):

```bash
git clone --recursive git@github.com:SHUSCT/SHU-CSAE.git

cd SHU-CSAE
```

Build required libraries:

```bash
bash ./scripts/build-libs.sh
```

<div align="center">

| Status | Experiment | Documentation | Platform (x64) |
|:------:|------------|:-------------:|:-------:|
| ❎ | Exp01: VM and SSH * | | |
| ✅ | Exp02: OpenMP | [Exp02-Tutor.md](./docs/Exp02-Tutor.md) | Linux/Windows |
| ⏩ | Exp03: MPI | [Exp03-Tutor.md](./docs/Exp03-Tutor.md) | Linux |
| ⏩ | Exp04: HPL | [Exp04-Tutor.md](./docs/Exp04-Tutor.md) | Linux |

</div>

*: Exp01 would be done in Exp03 for environment setup.

