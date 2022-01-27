/**
 */
package main

func main() {
	var isa IStudyAbroad
	isa = &StudyInAmerica{
		StudyAbroad: &StudyAbroad{},
	}
	TemplateMethod(isa)
}
