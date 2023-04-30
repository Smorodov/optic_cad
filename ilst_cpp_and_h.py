from pathlib import Path
import os

partnt_path=Path(__file__).parent.absolute()
includes=set()
sources=set()
headers=set()

for path in Path('./').rglob('*.h'):            
    headers.add(path.as_posix())    
    includes.add(os.path.dirname(path.as_posix()))

for path in Path('./').rglob('*.cxx'):            
    sources.add(path.as_posix())    

sources=sorted(sources)
headers=sorted(headers)

print('set( headers ')
for hdr in headers:
    print('"'+str(hdr)+'\"')
print(')\n')

print('set( sources ')
for src in sources:
    print('"'+str(src)+'\"')
print(')')

for inc in includes:
    print('include_directories(\"'+inc+'\")')