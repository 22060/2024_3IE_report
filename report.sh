#このスクリプトを作成することによりレポートのファイルを作成する。
#ディレクトリの選択を引数で数字でできるようにする。
#ディレクトリを作成した後は台に引数からディレクトリ名を取得し、そのディレクトリを作成する。
#最後に、そのディレクトリにmain.cファイルとbuild/Debugディレクトリを作成する。

#!/bin/bash

# Prompt the user to enter the directory name
read -p "Enter the directory name: " dir_name

# Create the directory
mkdir -p "/home/kj/report/2024_3IE_report/$dir_name"

# Create the main.c file
touch "/home/kj/report/2024_3IE_report/$dir_name/main.c"

# Create the build/Debug directory
mkdir -p "/home/kj/report/2024_3IE_report/$dir_name/build/Debug"