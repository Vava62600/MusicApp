all: build-linux build-windows

build-linux:
	./scripts/build_linux.sh

build-windows:
	./scripts/build_windows.ps1
