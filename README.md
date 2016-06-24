# roman-kata-c
Roman numeral calculator kata implemented in C with Check unit tests

Todo:
1. More exploratory testing
2. Extract "acceptance" tests into separate module.  E.g. birthday tests.
3. Move compression table and functions into its own module
4. Remove derived artifacts that were accidentally added to git
5. Subtract does not confirm result is >= 0
6. Clean up naming inconsistencies
7. Doesn't reject bad order of digits.  E.g. IIIV

Other ideas:
* Implement math directly in Roman numerals.  I.e. don't "cheat" by converting to Arabic.
* Explore naming conventions appropriate to TDD
* Explore modularization to simulate classes
* Explore making the tests more readable
* Explore separating the assertions into separate tests (without overwhelming boilerplate)

