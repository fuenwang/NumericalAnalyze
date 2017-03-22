#! /usr/bin/env python

import os
import sys
import subprocess

def CreateConfig(name):
    f = open("%s/config.txt"%name, 'w')
    f.write(name+'\n');
    f.close()

if len(sys.argv) == 1:
    print 'No dir name specify'
    exit()

if os.path.isdir(sys.argv[1]):
    print "Dir exist"
    exit()

else:
    print "Create Dir %s"%sys.argv[1]
    subprocess.call("mkdir %s"%sys.argv[1], shell=True)
    CreateConfig(sys.argv[1])
    d = os.path.abspath(os.path.dirname(__file__))
    subprocess.call('cp %s/Submit.py %s'%(d, sys.argv[1]), shell=True)
