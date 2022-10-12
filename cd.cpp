#include<iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

using namespace std;

string prevPathCD ; 

string get_path() {

	char *wd(getcwd(NULL,0));     // current working directory
  	string cwd(wd);
 	free(wd);
  	return cwd ;
}
	

int cd(string curDir , string newDir) {
	
	string path = prevPathCD;
	string cwdpath;
        int rc = -1 ;
	if (newDir == "-") {                      // "-" move to last directory path
		string temp = get_path();        // "-"  Last path where user switched to target path
                rc = chdir(path.c_str());
		prevPathCD = temp ;
                cout << get_path() << endl ;
	}
	else {	
		rc = chdir(curDir.c_str());               //switched to source directory from given arguments
		if (rc < 0)  {
			cout << "bash: cd: "<< curDir << ": No such file or directory" << endl;
			return 1 ;
		}

		rc = chdir(newDir.c_str());         //switch to target directory from given arguments
		if (rc < 0)  {
			cout << "bash: cd: "<< newDir << ": No such file or directory" << endl;
			return 1 ;
		}
		cwdpath = get_path();
		cout<<cwdpath<<endl;
	}
	return 0; 
}

int main(int argc,char *argv[] )
{
	if(argc <3){					//checking valid inputs from command line
		cout<<"Invalid no of arguments"<<endl;
		return 0;
	}

	string curDirectory = argv[1];
	string newDirectory = argv[2];

	cd(curDirectory,newDirectory); 
	return 0;
}
