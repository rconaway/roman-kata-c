# roman-kata-c
Roman numeral calculator kata implemented in C with Check unit tests

Todo:
* More exploratory testing
* Extract "acceptance" tests into separate module.  E.g. birthday tests.
* Move compression table and functions into its own module
* Subtract does not confirm result is >= 0
* Clean up naming inconsistencies
* Doesn't reject bad order of digits.  E.g. IIIV

Other ideas:
* Implement math directly in Roman numerals.  I.e. don't "cheat" by converting to Arabic.
* Explore naming conventions appropriate to TDD
* Explore modularization to simulate classes
* Explore making the tests more readable
* Explore separating the assertions into separate tests (without overwhelming boilerplate)

