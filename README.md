# SimpleServer
![](https://img.shields.io/badge/license-MIT-yellowgreen.svg)![](https://img.shields.io/badge/version-0.1-blue.svg)![](https://img.shields.io/badge/build-passing-green.svg)<a href="https://blog.lengyu.me">![](https://img.shields.io/badge/blog-reference-informational.svg)</a>

## About

This is an open source http server. It use multithread to improve performance. It's a toy,so you shouldn't use it in production environment. It was just used to learn how to use cpp to programme the network application.

## How to build

Firstly, We should install gcc and cmake.

**Note**: gcc version should be more than 8.2.

And then,install <a href="https://github.com/jbeder/yaml-cpp">yarm-cpp</a>. We used it to parse yaml format.

Finally, build it 

```commonlisp
cmake .
make && make install
```

If the system tell you that you have no permissions to copy file, you should use sudo to do it.

**Note**: you can use CMAKE_INSTALL_PREFIX to choose where to installed.

## Feature

* multithread support
* cache support
* asynchronous log support

## Change Log

### 0.1

* make&&make install support
* threads configuration support
