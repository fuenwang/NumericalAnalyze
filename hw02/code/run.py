import subprocess
import os

lst = [x for x in sorted(os.listdir('..')) if x.endswith('.dat')]
print lst
for one in lst:
    print one
    f = open('raw_record/record.txt', 'a')
    f.write('******************************************\n')
    f.close()
    cmd = '(time ./a.out %s < ../%s) >> raw_record/record.txt 2>&1 3>&1'%(one , one)
    print cmd
    subprocess.call(cmd, shell=True)
    f = open('raw_record/record.txt', 'a')
    f.write('******************************************\n')
    f.close()
