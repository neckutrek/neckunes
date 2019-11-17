#!/usr/bin/env python

from distutils.core import setup

setup(name='neckunes',
      version='0.1',
      description='Accidental NES Emulator',
      author='Marcus johansson',
      author_email='na',
      url='http://www.neckutrek.se/',
      packages=['neckunes'],
      entry_points = {
            'console_scripts': [
                  'neckunes = neckunes.main:main',                  
            ],              
          }
     )
