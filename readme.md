![](assets/logo.png)

KScott's Corruptor. .rotpurroC s'ttocSK

## State of Production ##

Very, very unfinished.

In fact, still a Hello World program at the time of
writing.

## Install ##

This program is written in [Node.js][0].

If you are installing on Windows, make sure
you check "put node in PATH" or whatever.

On most Linux distributions, you can just install the "npm" package
with whatever package manager you have.

e.g. `pacman -Sy npm`, `apt install npm`...

[0]: https://nodejs.org/

Make sure you have the required tools for [NodeGui][1].

See [the NodeGui Getting started page][2] for
detailed and up-to-date information.

[1]: https://nodegui.org/
[2]: https://docs.nodegui.org/docs/guides/getting-started/

NodeGui requirements rewritten here for lazy people like me
(as of 1/3/2020):

- A 64-bit OS
- CMake 3.1+
- NodeJS 12.x+
- Make/GCC v7 (MacOS/Linux)
- Visual Studio >=2017 (Windows)
- `pkg-config` and `build-essential` (Ubuntu)

After that, it's as simple as typing

```
git clone https://github.com/KScottDB/kcorock.git
cd kcorock
npm i
npm start
```

in your shell.