### Process from C++ code to a final executable

1. **preprocessor**가 실행되며, '#'으로 시작하는 directives(지시문)를 파싱한다.(문자열을 의미있는 token(구문)으로 분해)  
  #include 지시자는 포함된 파일을 하위 파일과 연결시킨다. preprocessor(전처리기)는 매크로를 다른 값으로 대체하거나 token-pasting을 수행한다.  
  
2. **compiler**는 전처리기 단계가 끝난 중간 파일에서 실행되며, assembler code를 만든다.

3. **assembler**는 assembly 파일에서 실행되며, 보통 object file이라 불리는 machine code를 만든다. 그리고 각 운영체제의 binary 실행 형식을 따른다.
예를 들어, Windows는 PE(portable executable format)을 Linux는 GNU를 사용하는 Unix System V ELF format을 사용한다.  
이 단계에서 symbols은 여전히 정의되지 않은 것으로 표시된다.

4. **linker**가 마지막으로 실행된다. 모든 object file에서 작동하며 symbols을 해석하고 target platform과 binary format에 의존하는 section이나 segment를 생성한다. 

* 링커 부분 설명 추가 필요.

