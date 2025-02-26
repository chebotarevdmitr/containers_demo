cd build
make
./ContainersDemo

┌──(dmitriy㉿kali)-[~/…/my_basic_course/dz/containers_demo/build]
└─$ ./ContainersDemo
=== Testing Sequential Container ===
After push_back(0-9): 0 1 2 3 4 5 6 7 8 9 
Size: 10
After erase(2,4,6): 0 1 3 5 7 8 9 
Size: 7
After insert(0,10): 10 0 1 3 5 7 8 9 
After insert(middle,20): 10 0 1 3 20 5 7 8 9 
Final state: 10 0 1 3 20 5 7 8 9 30 

=== Testing List Container ===
After push_back(0-9): 0 1 2 3 4 5 6 7 8 9 
Size: 10
After erase(2,4,6): 0 1 3 5 7 8 9 
Size: 7
After insert(0,10): 10 0 1 3 5 7 8 9 
After insert(middle,20): 10 0 1 3 20 5 7 8 9 
Final state: 10 0 1 3 20 5 7 8 9 30 
