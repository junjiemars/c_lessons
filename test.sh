#!/bin/sh

_ROOT_DIR_="`cd -- $(dirname -- $0) && pwd`"
_TEST_="${_TEST_:-basic}"
_CFG_OPT_="${_CFG_OPT_}"
_OS_NAME_="`uname -s 2>/dev/null`"
_WIN_ENV_=
_WIN_ENV_MSVC_=

case "$_OS_NAME_" in
  MSYS_NT-*|MINGW??_NT-*) _OS_NAME_="WinNT" ;;
esac

CC="${CC}"
if [ -z "$CC" ]; then
  case "$_OS_NAME_" in
    Darwin)  CC="clang" ;;
    Linux)   CC="gcc"   ;;
    WinNT)   CC="cl"    ;;
  esac
fi

# switch to ROOT
cd "${_ROOT_DIR_}"

# check nore
if [ ! -f "${_ROOT_DIR_%/}/configure" ]; then
  curl -O "https://raw.githubusercontent.com/junjiemars/nore/edge/bootstrap.sh" -o bootstrap.sh
  if [ 0 -ne $? ]; then
    echo "!panic: install Nore failed"
    exit 1
  fi
  sh bootstrap.sh --branch=edge
  rm bootstrap.sh
fi

# check cc-env for cl
if [ "WinNT" = "${_OS_NAME_}" -a "cl" = "${CC}" ]; then
  if [ ! -f "${HOME}/.nore/cc-env.sh" ]; then
    echo "!panic: ${HOME}/.nore/cc-env.sh no found"
    exit 1
  fi
  ${HOME}/.nore/cc-env.sh 1
  if [ ! -f "${HOME}/.nore/cc-env.bat" ]; then
    echo "!panic: ${HOME}/.nore/cc-env.bat no found"
    exit 1
  fi
  cat << END > "${HOME}/msvc.bat"
@if not "%VSCMD_DEBUG%" GEQ "3" echo off
REM generated by Nore (https://github.com/junjiemars/nore)
call "%1"
sh "%2"
"%3"
END
  if [ ! -f "${HOME}/msvc.bat" ]; then
    echo "!panic: generate ${HOME}/msvc.bat failed"
    exit 1
  fi
  _WIN_ENV_MSVC_="${HOME}/msvc.bat"
  chmod u+x "${_WIN_ENV_MSVC_}"
  _WIN_ENV_="${HOME}/.nore/cc-env.bat"
fi

test_do() {
  local rc=0
  local cfg="$_CFG_OPT_ $*"
  if [ -z "$_WIN_ENV_" ]; then
    echo "${_ROOT_DIR_%/}/configure $cfg"
    ${_ROOT_DIR_%/}/configure $cfg
    make test
  else
    echo "${_WIN_ENV_MSVC_} $_WIN_ENV_ ./configure $cfg"
    ${_WIN_ENV_MSVC_} "$_WIN_ENV_" "./configure $cfg" "make test"
  fi
  rc=$?
  if [ 0 -ne $rc ]; then
    echo "------------"
    echo "! $@ <failed>"
    echo "------------"
  fi
  return $rc
}

# basic test
if [ "basic" = "$_TEST_" ]; then
  test_do --has-algo
  test_do --has-cpu
  test_do --has-ds
  test_do --has-flex
  test_do --has-hi
  test_do --has-io
  test_do --has-lang
  test_do --has-leptonica
  test_do --has-library
  test_do --has-memory
  test_do --has-nginx
  test_do --has-os
  test_do --has-parallel
  test_do --has-regexp
  test_do --has-unicode
  test_do --has-uv --with-std=no
  test_do --has-x86
fi

echo "!completed"

# eof
