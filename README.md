# window container

## Build

1. 修改 `CMakeLists.txt` 中的 `CMAKE_PREFIX_PATH` 为正确的路径
2. 通过以下命令构建 Release 版本
```bash
cmake -Bbuild
cmake --build build -j16 --config Release
```
3. 使用对应版本的 `windeployqt` 工具进行依赖项拷贝
```bash
C:\Qt\5.15.2\msvc2019_64\bin\windeployqt.exe window_container.exe
```

## Screenshot
![1689339092922](https://github.com/ohto-ai/window_container/assets/46275725/c10b87b8-d0bc-4520-8557-0d5791d69a85)
