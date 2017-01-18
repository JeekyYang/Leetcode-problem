#!/bin/bash
# Description: find all missing files and directories, then copy them into the destination
SourceDir=~/Desktop/test123/source
TargetDir=~/Desktop/test123/target
echo $SourceDir
diff -qr $SourceDir $TargetDir | grep -v target | while read line 
do
	echo "= = = == = line: $line"
	# get the path suffix
	param1=`echo "$line" | awk -F : {'print $1'} | awk {'print $3'}`
	param2=`echo "$line" | awk -F : {'print $2'} | awk {'print $1'}`
	echo "param1: $param1"
	echo "param2: $param2"
	delta=`echo ${param1:${#SourceDir}}`
	path="$param1/$param2"
	targetPath=$TargetDir/$delta
	if [ -d $path ]; then
		echo "this is directory"
		cp -r $path $targetPath
	elif [ -f $path ]; then
		echo "this is a file"
		cp $path $targetPath
	else
		echo "Error"
		exit 101
	fi
done

