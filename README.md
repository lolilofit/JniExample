# JniExample

1. Первая часть задания была выполнена на Windows10. 
   Состоит из: JniProject/Main.java, JniProjectC/library.c, JniProjectC/CMakeLists.txt
   Сборка с-части с cmake: 

   ```cmake --build SomePath\cmake-build-release --target JniProject -- -j 2```
   
   Запуск java части:
   
   ```java -Djava.library.path="SomePath\cmake-build-release" Main```
   
   2. Вторая часть задания выполнялась в докере на debian.
      Состоит из JniProject/MainP.java, JniProjectC/main.c
      Файл main.bc собран с clang и graalvm для java11.
      
   
