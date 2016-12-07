###UnitySkeleton

This skeleton includes an intuitive directory structure as well as a Makefile that automatically finds and builds your tests using GNUMake.  This is all meant to be super simple, no magic, no extra tools or libraries, just Unity and GNUMake.  Just write your Unity tests in the ```test``` directory and title them with the prefix "Test".  The rest of the test name must correspond to one of your source files in the ```src``` directory.  So if I have a file named ```src/HelloWorld.c``` I can write my tests in ```test/TestHelloWorld.c```

Makefile commands (run in the root directory):

```bash
make TestAll #Make and run all the tests
make TestClean #Clean the test intermediates
make Test*** #Run a specific test by name (corresponds to src file name)
make clobber #delete "build" directory
make *** #Run rule specified in src.mk makefile
```

Since UnitySkeleton contains and requires the Unity submodule you must run the following commands before using to pull Unity:

```bash
git submodule init
git submodule update
```
