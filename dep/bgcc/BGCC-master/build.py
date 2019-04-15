import platform
import os

osName = platform.system()

if osName == 'Windows':
	os.system('build.bat')
elif osName == 'Linux':
	os.system('make -f Makefile')

