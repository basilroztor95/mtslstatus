#!/bin/bash

ping -c 1 -q 8.8.8.8 &> /dev/null && echo 'i' || echo 'no internet'
