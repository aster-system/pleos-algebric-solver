//******************
//
// pleos_algebric_solver.cpp
//
//******************
// Presentation :
//
// PLEOS, by Aster System, is a project which aims education.
// By using the power of SCLS and other Aster System's tools, we created  this.
// We want to make education easier for everyone (teachers, as students and pupils).
// The software is made in french, because the main goal is France educational system.
//
// The "Algebric Solver" part aims mathematics lessons.
// Its goal is to solve a lot of communs problems quickly.
//
// This file contains the source code of pleos_algebric_solver.h.
//
//******************
//
// License (GPL V3.0) :
//
// Copyright (C) 2024 by Aster System, Inc. <https://aster-system.github.io/aster-system/>
// This file is part of PLEOS.
// PLEOS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PLEOS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with PLEOS. If not, see <https://www.gnu.org/licenses/>.
//

// Include pleos_algebric_solver.h
#include "../headers/pleos_algebric_solver.h"

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    // Algebric_Solver_Page constructor
    Algebric_Solver_Page::Algebric_Solver_Page(scls::_Window_Advanced_Struct* window_struct, std::string name) : scls::GUI_Page(window_struct, name) {}

    // Loads an object in a page from XML
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        std::shared_ptr<scls::GUI_Object> to_return;

        // Check navigation
        to_return = __create_loaded_object_from_type_navigation(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;

        // Check page by page
        to_return = __create_loaded_object_from_type_complex_number(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_functions(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_home(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_matrices(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_number_theory(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_probabilities(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;
        to_return = __create_loaded_object_from_type_sequences(object_name, object_type, parent);
        if(to_return.get() != 0) return to_return;

        // Classic object creation
        return GUI_Page::__create_loaded_object_from_type(object_name, object_type, parent);
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_complex_number(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_complex_number_body") {
            a_complex_number_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_complex_number_page;
        }
        else if(object_name == "algebric_solver_complex_number_simplify") {
            a_complex_number_simplify_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_complex_number_simplify_button;
        }
        else if(object_name == "algebric_solver_complex_number_simplify_input") {
            a_complex_number_simplify_input = *parent->new_object<scls::GUI_Text_Input>(object_name);
            return a_complex_number_simplify_input;
        }
        else if(object_name == "algebric_solver_complex_number_simplify_result") {
            a_complex_number_simplify_result = *parent->new_object<scls::GUI_Text>(object_name);
            return a_complex_number_simplify_result;
        }
        return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_functions(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_functions_body") {
            a_functions_page = *parent->new_object<scls::GUI_Text>(object_name);
            return a_functions_page;
        } else if(object_name == "algebric_solver_functions_analyse_elements") {
            a_functions_analyse_elements = *parent->new_object<scls::GUI_Scroller>(object_name);
            return a_functions_analyse_elements;
        } else if(object_name == "algebric_solver_functions_analyse_elements_value") {
            a_functions_analyse_elements_value_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_functions_analyse_elements_value_button;
        } else if(object_name == "algebric_solver_functions_analyse_elements_limit") {
            a_functions_analyse_elements_limit_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_functions_analyse_elements_limit_button;
        } else if(object_name == "algebric_solver_functions_redaction") {
            a_functions_redaction = *parent->new_object<scls::GUI_Text>(object_name);
            a_functions_redaction.get()->set_max_width(800);
            return a_functions_redaction;
        } else if(object_name == "algebric_solver_functions_analyse") {
            a_functions_analyse_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_functions_analyse_button;
        } else if(object_name == "algebric_solver_functions_analyse_input") {
            a_functions_analyse_input = *parent->new_object<scls::GUI_Text_Input>(object_name);
            return a_functions_analyse_input;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_home(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_home_body") {
            a_home_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_home_page;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_matrices(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_matrices_body") {
            a_matrices_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_matrices_page;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_navigation(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_navigation_complex_number_button") {
            a_complex_number_navigation_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_complex_number_navigation_button;
        } else if(object_name == "algebric_solver_navigation_home_button") {
            a_home_navigation_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_home_navigation_button;
        } else if(object_name == "algebric_solver_navigation_function_button") {
            a_function_navigation_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_function_navigation_button;
        } else if(object_name == "algebric_solver_navigation_matrices_button") {
            a_matrices_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_matrices_button;
        } else if(object_name == "algebric_solver_navigation_number_theory_button") {
            a_number_theory_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_number_theory_button;
        } else if(object_name == "algebric_solver_navigation_probabilities_button") {
            a_probabilities_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_probabilities_button;
        } else if(object_name == "algebric_solver_navigation_sequences_button") {
            a_sequences_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_sequences_button;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_number_theory(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_number_theory_body") {
            a_number_theory_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_number_theory_page;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_probabilities(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_probabilities_body") {
            a_probabilities_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_probabilities_page;
        } else if(object_name == "algebric_solver_probabilities_tree_create") {
            a_probabilities_tree_create = *parent->new_object<scls::GUI_Text>(object_name);
            return a_probabilities_tree_create;
        } else if(object_name == "algebric_solver_probabilities_universe") {
            a_probabilities_universe = *parent->new_object<scls::GUI_Scroller>(object_name);
            return a_probabilities_universe;
        } else if(object_name == "algebric_solver_probabilities_universe_add_element") {
            a_probabilities_universe_add_element = *parent->new_object<scls::GUI_Text>(object_name);
            return a_probabilities_universe_add_element;
        } else if(object_name == "algebric_solver_probabilities_universe_add_element_conditionnal") {
            a_probabilities_universe_add_element_conditionnal = *parent->new_object<scls::GUI_Text>(object_name);
            return a_probabilities_universe_add_element_conditionnal;
        } else if(object_name == "algebric_solver_probabilities_redaction") {
            a_probabilities_redaction = *parent->new_object<scls::GUI_Text>(object_name);
            a_probabilities_redaction.get()->set_max_width(800);
            return a_probabilities_redaction;
        } return std::shared_ptr<scls::GUI_Object>();
    }
    std::shared_ptr<scls::GUI_Object> Algebric_Solver_Page::__create_loaded_object_from_type_sequences(std::string object_name, std::string object_type, scls::GUI_Object* parent) {
        if(object_name == "algebric_solver_sequences_body") {
            a_sequences_page = *parent->new_object<scls::GUI_Object>(object_name);
            return a_sequences_page;
        } else if(object_name == "algebric_solver_sequences_analyse") {
            a_sequences_analyse_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_sequences_analyse_button;
        } else if(object_name == "algebric_solver_sequences_analyse_add_recursion") {
            a_sequences_analyse_add_recursion_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_sequences_analyse_add_recursion_button;
        } else if(object_name == "algebric_solver_sequences_analyse_input") {
            a_sequences_analyse_input = *parent->new_object<scls::GUI_Text_Input>(object_name);
            return a_sequences_analyse_input;
        } else if(object_name == "algebric_solver_sequences_analyse_input_start") {
            a_sequences_analyse_input_start = *parent->new_object<scls::GUI_Text>(object_name);
            return a_sequences_analyse_input_start;
        } else if(object_name == "algebric_solver_sequences_analyse_recursions") {
            a_sequences_analyse_recursions = *parent->new_object<scls::GUI_Object>(object_name);
            return a_sequences_analyse_recursions;
        } else if(object_name == "algebric_solver_sequences_redaction") {
            a_sequences_redaction = *parent->new_object<scls::GUI_Text>(object_name);
            a_sequences_redaction.get()->set_max_width(800);
            return a_sequences_redaction;
        } return std::shared_ptr<scls::GUI_Object>();
    }

    //******************
    //
    // Functions handling
    //
    //******************

    // Convert a string to a polymonial with functions datas
    scls::Formula Algebric_Solver_Page::functions_string_to_formula() {scls::String_To_Formula_Parse parser;return parser.string_to_formula(functions_analyse_input());}
    // Load an image finder in the elements
    Algebric_Solver_Page::__Function_Analyse_Element& Algebric_Solver_Page::load_function_analyse_element(unsigned char type) {
        Algebric_Solver_Page::__Function_Analyse_Element new_element;

        // Create the parent object
        std::string object_name = a_functions_analyse_elements.get()->name() + "-object_" + std::to_string(a_functions_analyse_elements_content.size());
        std::shared_ptr<scls::GUI_Object> current_object = *a_functions_analyse_elements.get()->new_object<scls::GUI_Object>(object_name);
        current_object.get()->set_border_width_in_pixel(1);
        current_object.get()->set_height_in_pixel(36);
        current_object.get()->set_width_in_scale(1);
        new_element.parent = current_object;
        // Create the title object
        std::shared_ptr<scls::GUI_Text> current_title = *current_object.get()->new_object<scls::GUI_Text>(object_name + "_title");
        current_title.get()->set_height_in_pixel(34);
        current_title.get()->set_width_in_scale(scls::Fraction(1, 2));
        current_title.get()->set_x_in_object_scale(scls::Fraction(1, 4));
        current_title.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        if(type == PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_IMAGE) {
            current_title.get()->set_text("Image de f pour x =");
        } else if(type == PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_LIMIT) {
            current_title.get()->set_text("Image de f pour x tendant vers");
        }
        new_element.title = current_title;

        // Add the element
        new_element.type = type;
        a_functions_analyse_elements_content.push_back(new_element);
        return a_functions_analyse_elements_content[a_functions_analyse_elements_content.size() - 1];
    }
    // Load an image finder in the elements
    void Algebric_Solver_Page::load_function_analyse_image_finder() {
        Algebric_Solver_Page::__Function_Analyse_Element& new_element = load_function_analyse_element(PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_IMAGE);

        // Create the image input
        std::string object_name = new_element.parent.get()->name();
        std::shared_ptr<scls::GUI_Text_Input> current_input = *new_element.parent.get()->new_object<scls::GUI_Text_Input>(object_name + "_image_input");
        current_input.get()->set_border_width_in_pixel(1);
        current_input.get()->set_height_in_pixel(32);
        current_input.get()->set_width_in_scale(scls::Fraction(1, 3));
        current_input.get()->set_x_in_object_scale(scls::Fraction(3, 4));
        current_input.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        new_element.single_input = current_input;

        // Place the elements in the scroller
        place_functions_analyse_elements();
    }
    // Load a limit finder in the elements
    void Algebric_Solver_Page::load_function_analyse_limit_finder() {
        Algebric_Solver_Page::__Function_Analyse_Element& new_element = load_function_analyse_element(PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_LIMIT);

        // Create the limit input
        std::string object_name = new_element.parent.get()->name();
        std::shared_ptr<scls::GUI_Text_Input> current_input = *new_element.parent.get()->new_object<scls::GUI_Text_Input>(object_name + "_image_input");
        current_input.get()->set_border_width_in_pixel(1);
        current_input.get()->set_height_in_pixel(32);
        current_input.get()->set_width_in_scale(scls::Fraction(1, 3));
        current_input.get()->set_x_in_object_scale(scls::Fraction(3, 4));
        current_input.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        new_element.single_input = current_input;

        // Place the elements in the scroller
        place_functions_analyse_elements();
    }

    //******************
    //
    // Probabilities handling
    //
    //******************

    // Add the base of a simple element in the universe
    Algebric_Solver_Page::__Probability_Universe_Element& Algebric_Solver_Page::__add_universe_element(unsigned char type) {
        Algebric_Solver_Page::__Probability_Universe_Element new_element;

        // Create the parent object
        std::string object_name = a_probabilities_universe.get()->name() + "-object_" + std::to_string(a_probabilities_universe_elements.size());
        std::shared_ptr<scls::GUI_Object> current_object = *a_probabilities_universe.get()->new_object<scls::GUI_Object>(object_name);
        current_object.get()->set_border_width_in_pixel(1);
        current_object.get()->set_height_in_pixel(36);
        current_object.get()->set_width_in_scale(1);
        new_element.parent = current_object;
        // Create the title object
        std::shared_ptr<scls::GUI_Text> current_title = *current_object.get()->new_object<scls::GUI_Text>(object_name + "_title_1");
        current_title.get()->set_height_in_pixel(28);
        current_title.get()->set_width_in_scale(scls::Fraction(1, 5));
        current_title.get()->set_x_in_object_scale(scls::Fraction(1, 10));
        current_title.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        current_title.get()->set_text("Évènement");
        new_element.title_1 = current_title;
        // Create the input for the name of the object
        std::shared_ptr<scls::GUI_Text_Input> name_input = *current_object.get()->new_object<scls::GUI_Text_Input>(object_name + "_name");
        name_input.get()->set_border_width_in_pixel(1);
        name_input.get()->set_height_in_pixel(26);
        name_input.get()->set_width_in_scale(scls::Fraction(1, 10));
        name_input.get()->set_x_in_object_scale(scls::Fraction(1, 4));
        name_input.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        new_element.name_input = name_input;
        // Create the final title object
        current_title = *current_object.get()->new_object<scls::GUI_Text>(object_name + "_title_final");
        current_title.get()->set_height_in_pixel(28);
        current_title.get()->set_width_in_scale(scls::Fraction(1, 10));
        current_title.get()->set_x_in_object_scale(scls::Fraction(3, 4));
        current_title.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        current_title.get()->set_text("est de");
        new_element.title_final = current_title;
        // Create the final input object
        std::shared_ptr<scls::GUI_Text_Input> final_input = *current_object.get()->new_object<scls::GUI_Text_Input>(object_name + "_input_final");
        final_input.get()->set_border_width_in_pixel(1);
        final_input.get()->set_height_in_pixel(26);
        final_input.get()->set_width_in_scale(scls::Fraction(1, 5));
        final_input.get()->set_x_in_object_scale(scls::Fraction(9, 10));
        final_input.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        new_element.final_input = final_input;

        // Add the element
        new_element.type = type;
        a_probabilities_universe_elements.push_back(new_element);
        return a_probabilities_universe_elements[a_probabilities_universe_elements.size() - 1];
    }
    // Add a simple element in the elements
    void Algebric_Solver_Page::add_probabilities_universe_element() {
        Algebric_Solver_Page::__Probability_Universe_Element& new_element = __add_universe_element(PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT);
        place_probabilities_universe_elements();
    }
    // Add a conditionnal element in the elements
    void Algebric_Solver_Page::add_probabilities_universe_element_conditionnal() {
        Algebric_Solver_Page::__Probability_Universe_Element& new_element = __add_universe_element(PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT_CONDITIONNAL);

        // Create the title 2
        std::string object_name = new_element.parent.get()->name();
        std::shared_ptr<scls::GUI_Text> current_title = *new_element.parent.get()->new_object<scls::GUI_Text>(object_name + "_title_2");
        current_title.get()->set_height_in_pixel(28);
        current_title.get()->set_width_in_scale(scls::Fraction(1, 5));
        current_title.get()->set_x_in_object_scale(scls::Fraction(2, 5));
        current_title.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        current_title.get()->set_text("sachant");
        new_element.title_2 = current_title;
        // Create the condition input
        std::shared_ptr<scls::GUI_Text_Input> condition_input = *new_element.parent.get()->new_object<scls::GUI_Text_Input>(object_name + "_condition_input");
        condition_input.get()->set_border_width_in_pixel(1);
        condition_input.get()->set_height_in_pixel(26);
        condition_input.get()->set_width_in_scale(scls::Fraction(1, 10));
        condition_input.get()->set_x_in_object_scale(scls::Fraction(11, 20));
        condition_input.get()->set_y_in_object_scale(scls::Fraction(1, 2));
        new_element.condition_input = condition_input;

        place_probabilities_universe_elements();
    }

    //******************
    //
    // Sequences handling
    //
    //******************

    // Adds a recursion to the sequence
    void Algebric_Solver_Page::sequences_add_recursion() {
        // Create the title
        std::shared_ptr<scls::GUI_Text> title = *a_sequences_analyse_recursions.get()->new_object<scls::GUI_Text>(a_sequences_analyse_recursions.get()->name() + "-title_" + std::to_string(a_sequences_analyse_recursions_titles.size()));
        title.get()->set_font_size(30);
        title.get()->set_height_in_pixel(30);
        title.get()->set_width_in_scale(scls::Fraction(1, 4));
        title.get()->set_x_in_object_scale(scls::Fraction(1, 3));
        if(a_sequences_analyse_recursions_titles.size() <= 0) title.get()->attach_top_in_parent();
        else title.get()->attach_bottom_of_object_in_parent(a_sequences_analyse_recursions_titles[a_sequences_analyse_recursions_titles.size() - 1]);
        title.get()->set_text("s(0) = ");
        // Create the value
        std::shared_ptr<scls::GUI_Text_Input> value = *a_sequences_analyse_recursions.get()->new_object<scls::GUI_Text_Input>(a_sequences_analyse_recursions.get()->name() + "-input_" + std::to_string(a_sequences_analyse_recursions_titles.size()));
        value.get()->set_border_width_in_pixel(1);
        value.get()->set_font_size(30);
        value.get()->set_height_in_pixel(30);
        value.get()->set_width_in_scale(scls::Fraction(1, 4));
        value.get()->set_x_in_object_scale(scls::Fraction(2, 3));
        if(a_sequences_analyse_recursions_titles.size() <= 0) value.get()->attach_top_in_parent();
        else value.get()->attach_bottom_of_object_in_parent(a_sequences_analyse_recursions_titles[a_sequences_analyse_recursions_titles.size() - 1]);
        // Add the elements
        a_sequences_analyse_recursions_titles.push_back(title);
        a_sequences_analyse_recursions_values.push_back(value);

        // Modify the sequence title
        update_sequences_title();

        a_sequences_analyse_recursions.get()->set_height_in_pixel(a_sequences_analyse_recursions.get()->height_in_pixel() + 30);
    }

    // Convert a string to a polymonial with sequences datas
    scls::Formula Algebric_Solver_Page::sequences_string_to_polymonial() {
        scls::String_To_Formula_Parse parser;
        parser.add_function("s");
        return parser.string_to_formula(sequences_analyse_input());
    }

    //******************
    //
    // Check the events
    //
    //******************

    // Check the complex number event
    void Algebric_Solver_Page::check_complex_number_events() {
        // Check if a simplification is needed
        if(a_complex_number_simplify_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            scls::Formula formula = scls::string_to_formula(complex_number_simplify_input());
            a_complex_number_simplify_result.get()->set_text(formula.to_std_string());
        }
    }

    // Check the functions event
    void Algebric_Solver_Page::check_functions_events() {
        if(a_functions_analyse_button.get() != 0 && a_functions_analyse_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // Analyse the text
            std::string functions_input = functions_analyse_input();
            if(functions_input != "") {
                // Create the redaction
                scls::Formula formula = functions_string_to_formula();
                std::string functions_input_simplify = formula.to_std_string();
                std::string final_text = "Nous avons la fonction f(x) = " + functions_input + " pour tout x appartenant à R.";
                final_text += " Nous pouvons la simplifier sous la forme f(x) = " + functions_input_simplify + ".</br></br>";
                // Do the needed analyse
                Function_Studied fs;
                fs.function_formula = formula;
                fs.function_name = "f";
                for(int i = 0;i<static_cast<int>(a_functions_analyse_elements_content.size());i++) {
                    if(a_functions_analyse_elements_content[i].type == PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_IMAGE) {
                        // Get the image of the function
                        scls::Formula value = scls::string_to_formula(a_functions_analyse_elements_content[i].single_input.get()->text());
                        function_image(fs, value, final_text);
                        final_text += "</br></br>";
                    } else if(a_functions_analyse_elements_content[i].type == PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_LIMIT) {
                        // Get the limit of the function
                        scls::Formula value = scls::string_to_formula(a_functions_analyse_elements_content[i].single_input.get()->text());
                        std::string needed_text = a_functions_analyse_elements_content[i].single_input.get()->text(); scls::Limit needed_limit;
                        if(needed_text == "+inf") {needed_limit.set_pi();}
                        else if(needed_text == "-inf") {needed_limit.set_mi();}
                        else if(needed_text == "0+") {needed_limit.set_pz();}
                        else if(needed_text == "0-") {needed_limit.set_mz();}
                        else {needed_limit = scls::Fraction::from_std_string(needed_text);}
                        function_limit(fs, needed_limit, final_text);
                        final_text += "</br></br>";
                    }
                }
                // Apply the redaction
                set_redaction(a_functions_redaction, final_text);
            }
        }

        // Check the elements
        if(a_functions_analyse_elements_value_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            load_function_analyse_image_finder();
        } if(a_functions_analyse_elements_limit_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            load_function_analyse_limit_finder();
        }
    }

    // Check the matrices event
    void Algebric_Solver_Page::check_matrices_events() {

    }

    // Check the navigation event
    void Algebric_Solver_Page::check_navigation_events() {
        if(a_complex_number_navigation_button.get() != 0 && a_complex_number_navigation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_complex_number_page();
        if(a_function_navigation_button.get() != 0 && a_function_navigation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_function_page();
        if(a_home_navigation_button.get() != 0 && a_home_navigation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_home_page();
        if(a_matrices_button.get() != 0 && a_matrices_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_matrices_page();
        if(a_number_theory_button.get() != 0 && a_number_theory_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_number_theory_page();
        if(a_probabilities_button.get() != 0 && a_probabilities_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_probabilities_page();
        if(a_sequences_button.get() != 0 && a_sequences_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_sequences_page();
    }

    // Check the probabilities event
    void Algebric_Solver_Page::check_probabilities_events() {
        // Create a tree
        if(a_probabilities_tree_create.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // Create the needed universe
            Probability_Universe universe;
            for(int i = 0;i<static_cast<int>(a_probabilities_universe_elements.size());i++) {
                Algebric_Solver_Page::__Probability_Universe_Element& element = a_probabilities_universe_elements[i];
                if(element.type == PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT) {
                    // Create a new direct element
                    universe.add_event(element.name_input.get()->text(), scls::Fraction::from_std_string(element.final_input.get()->text()));
                } else if(element.type == PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT_CONDITIONNAL) {
                    // Create a new element, conditionally to another
                    universe.add_event_conditionally(element.name_input.get()->text(), scls::Fraction::from_std_string(element.final_input.get()->text()), element.condition_input.get()->text());
                }
            }

            // Create the redaction
            std::string final_text = universe.description();
            // Apply the redaction
            set_redaction(a_probabilities_redaction, final_text);
            universe.tree().get()->save_png("tests/tree.png");
        }

        // Check the universe
        if(a_probabilities_universe_add_element.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            add_probabilities_universe_element();
        } if(a_probabilities_universe_add_element_conditionnal.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            add_probabilities_universe_element_conditionnal();
        }
    }

    // Check the sequences event
    void Algebric_Solver_Page::check_sequences_events() {
        if(a_sequences_analyse_add_recursion_button.get() != 0 && a_sequences_analyse_add_recursion_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // Add a recursion to the sequence
            sequences_add_recursion();
        }

        if(a_sequences_analyse_button.get() != 0 && a_sequences_analyse_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) {
            // Analyse the text
            std::string sequence_input = sequences_analyse_input();
            if(sequence_input != "") {
                // Create the redaction
                scls::Formula polymonial = sequences_string_to_polymonial();
                std::string sequence_input_simplify = polymonial.to_std_string();
                std::string final_text = "Nous avons la suite s(n) = " + sequence_input + " pour tout n appartenant à N. ";
                final_text += "Nous pouvons la simplifier sous la forme s(n) = " + sequence_input_simplify + ".</br></br>";
                // Study the variation of the function
                Function_Studied fs;
                fs.function_formula = polymonial;
                fs.function_name = "s";
                fs.function_unknown = "n";
                sequence_variation(fs, final_text);
                // Apply the redaction
                a_sequences_redaction.get()->set_text(final_text);
                a_sequences_redaction.get()->set_height_in_pixel(a_sequences_redaction.get()->texture()->get_image()->height());
            }
        }
    }

    // Update the events
    void Algebric_Solver_Page::update_event() {
        GUI_Page::update_event();

        // Check the navigation event
        check_navigation_events();

        // Complex number events
        if(current_page() == PLEOS_ALGEBRIC_SOLVER_COMPLEX_NUMBER_PAGE) check_complex_number_events();
        // Function events
        if(current_page() == PLEOS_ALGEBRIC_SOLVER_FUNCTION_PAGE) check_functions_events();
        // Matrices events
        if(current_page() == PLEOS_ALGEBRIC_SOLVER_MATRICES_PAGE) check_matrices_events();
        // Probabilities events
        if(current_page() == PLEOS_ALGEBRIC_SOLVER_PROBABILITIES_PAGE) check_probabilities_events();
        // Sequences events
        if(current_page() == PLEOS_ALGEBRIC_SOLVER_SEQUENCES_PAGE) check_sequences_events();
    }

    //******************
    //
    // Handle the pages
    //
    //******************

    // Displays the complex number page
    void Algebric_Solver_Page::display_complex_number_page() {
        hide_all();
        if(a_complex_number_page.get() != 0) a_complex_number_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_COMPLEX_NUMBER_PAGE);
    }

    // DIsplays the function page
    void Algebric_Solver_Page::display_function_page() {
        hide_all();
        if(a_functions_page.get() != 0) a_functions_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_FUNCTION_PAGE);
    }

    // Displays the home page
    void Algebric_Solver_Page::display_home_page() {
        hide_all();
        if(a_home_page.get() != 0) a_home_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_HOME_PAGE);
    }

    // Displays the number theory page
    void Algebric_Solver_Page::display_matrices_page() {
        hide_all();
        if(a_matrices_page.get() != 0) a_matrices_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_MATRICES_PAGE);
    }

    // Displays the number theory page
    void Algebric_Solver_Page::display_number_theory_page() {
        hide_all();
        if(a_number_theory_page.get() != 0) a_number_theory_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_NUMBER_THEORY_PAGE);
    }

    // Displays the probability page
    void Algebric_Solver_Page::display_probabilities_page() {
        hide_all();
        if(a_probabilities_page.get() != 0) a_probabilities_page.get()->set_visible(true);

        // Set the needed datas
        unload_probabilities_universe();
        set_current_page(PLEOS_ALGEBRIC_SOLVER_PROBABILITIES_PAGE);
    }

    // Displays the sequences page
    void Algebric_Solver_Page::display_sequences_page() {
        hide_all();
        if(a_sequences_page.get() != 0) a_sequences_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_SEQUENCES_PAGE);
        // Configure the UI elements
        update_sequences_title();
    }

    // Hides all the pages
    void Algebric_Solver_Page::hide_all() {
        if(a_complex_number_page.get() != 0) a_complex_number_page.get()->set_visible(false);
        if(a_functions_page.get() != 0) a_functions_page.get()->set_visible(false);
        if(a_home_page.get() != 0) a_home_page.get()->set_visible(false);
        if(a_matrices_page.get() != 0) a_matrices_page.get()->set_visible(false);
        if(a_number_theory_page.get() != 0) a_number_theory_page.get()->set_visible(false);
        if(a_probabilities_page.get() != 0) a_probabilities_page.get()->set_visible(false);
        if(a_sequences_page.get() != 0) a_sequences_page.get()->set_visible(false);

        // Clear the sequences part
        unload_sequences();
        a_sequences_analyse_recursions.get()->delete_children();
        a_sequences_analyse_recursions.get()->set_height_in_pixel(0);
    }
}
