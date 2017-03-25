#! /usr/bin/env python

import subprocess

f = open('config.txt', 'r')

name = f.read().replace("\n", "")
print name

subprocess.call('mkdir submit', shell=True)
command = 'cp code/%s.cpp code/MAT.h code/MAT.cpp code/VEC.h code/VEC.cpp code/makefile doc/%sa.pdf submit/'%(name,name)

subprocess.call(command, shell=True)
