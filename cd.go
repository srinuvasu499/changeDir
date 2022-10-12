package main

import (
    "fmt"
    "os"
)
func cd(curDir string ,newDir string) int {

    err :=  os.Chdir(curDir)		//switched to source directory from given argument
    if err != nil {
	    fmt.Printf("%s: No such file or directory\n",curDir)
	    return -1
    }

    err1 :=  os.Chdir(newDir)		 //switch to target directory from given arguments
    if err1 != nil {
	    fmt.Printf("%s: No such file or directory\n",newDir)
	    return -1
    }

    temp2, err := os.Getwd()		// Get current directory
    if err != nil {
	    fmt.Printf("%s: No such file or directory\n",newDir)
	    return -1
    }
    fmt.Println(temp2)
    return 0

}

func main() {

	noArg := len(os.Args)

	if noArg < 3 {			//checking valid inputs from command line
		fmt.Printf("Invalid no of arguments")
		return 
	}
	oldDirectory := os.Args[1]
	newDirectory := os.Args[2]

	cd(oldDirectory,newDirectory)
}
