# Visual Studio Code tutorial

### Environment
* OS : Ubuntu 16.04 / Windows 10

### 1. 설치  
  * 사용자 환경에 맞게 설치한다.
[Install](https://code.visualstudio.com/download)

### 2. workspace 생성  
  * Visual Studio Code는 디렉토리(폴더)로 프로젝트를 구분하기 때문에 따로 디렉토리를 만들어주어야 한다.
  * Tab Menu: File > OpenFolder > 생성한 디렉토리 > xxx.cpp(파일 생성)  
### 3. compile & execute
  * Ctrl+Shift+p > task > Configure Default Build Task > Create tasks.json file from template > Others
  * 바이너리 실행 부분이 Ubuntu와 Windows가 다르니 주의
 #### tasks.json 
 ```javascript
 {
    "version": "2.0.0",
    "runner": "terminal",
    "type": "shell",
    "echoCommand": true,
    "presentation" : { "reveal": "always" },
    "tasks": [
          //C++ 컴파일
          {
            "label": "save and compile for C++",
            "command": "g++",
            "args": [
                "${file}",
                "-g",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "group": "build",

            //컴파일시 에러를 편집기에 반영
            //참고:   https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher

            "problemMatcher": {
                "fileLocation": [
                    "relative",
                    "${workspaceRoot}"
                ],
                "pattern": {
                    // The regular expression. 
                   //Example to match: helloWorld.c:5:3: warning: implicit declaration of function 'prinft'
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
        },
        //C 컴파일
        {
            "label": "save and compile for C",
            "command": "gcc",
            "args": [
                "${file}",
                "-g",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "group": "build",

            //컴파일시 에러를 편집기에 반영
            //참고:   https://code.visualstudio.com/docs/editor/tasks#_defining-a-problem-matcher

            "problemMatcher": {
                "fileLocation": [
                    "relative",
                    "${workspaceRoot}"
                ],
                "pattern": {
                    // The regular expression. 
                   //Example to match: helloWorld.c:5:3: warning: implicit declaration of function 'prinft'
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
        },
        // 바이너리 실행(Ubuntu)

        {

            "label": "execute",

            "command": "cd ${fileDirname} && ./${fileBasenameNoExtension}",

            "group": "test"

        }
        // // 바이너리 실행(Windows)
        // {
        //     "label": "execute",
        //     "command": "cmd",
        //     "group": "test",
        //     "args": [
        //         "/C", "${fileDirname}\\${fileBasenameNoExtension}"
        //     ]
    
        // }
    ]
}
```
### 4. shortcut(단축키) 설정
  * Ctrl+k+s > keybindings.json 클릭
#### keybindings.json
```javascript
// Place your key bindings in this file to override the defaults
[
    //compile
    { "key": "ctrl+shift+c", "command": "workbench.action.tasks.build" },
    
    //execute
    { "key": "ctrl+shift+e", "command": "workbench.action.tasks.test" }
]
```
  * 각 단축키를 누르면 컴파일, 실행을 수행한다.  
  
### 5. Debugging 설정
  * 컴파일 후 F5를 누르면 launch.json 파일이 열린다.
  #### launch.json 
  * Ubuntu
  ```javascript
  {
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```
  * Windows
  ```javascript
  {
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe",

            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/MinGW/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]

        }
    ]
}
```
  * code의 라인 번호 왼쪽에 breakpoint를 설정하고 Debug를 한다.
