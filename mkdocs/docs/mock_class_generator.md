# Mock Class Generator

Unlike other mocking frameworks, we ship with a mock class generator that is built along with
the project that parses a given header and output the equivalent mock class header.

Do keep in mind that this is just a rough header parser so manual adjustment might
still be needed. For more details, do `GenerateMockClass --help`.

To write the output to a file on Unix do

```shell
./GenerateMockClass <options...> <input header> > ./MyMockClass.hpp
```

or in Windows Powershell

```powershell
./GenerateMockClass <options...> <input header> | Set-Content -Encoding UTF8NoBOM ./MyMockClass.hpp
```
