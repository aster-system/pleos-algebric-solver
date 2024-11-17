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
        to_return = __create_loaded_object_from_type_number_theory(object_name, object_type, parent);
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
        } else if(object_name == "algebric_solver_navigation_number_theory_button") {
            a_number_theory_button = *parent->new_object<scls::GUI_Text>(object_name);
            return a_number_theory_button;
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
    scls::Formula Algebric_Solver_Page::functions_string_to_polymonial() {scls::String_To_Formula_Parse parser;return parser.string_to_formula(functions_analyse_input());}

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
                scls::Formula polymonial = functions_string_to_polymonial();
                std::string functions_input_simplify = polymonial.to_std_string();
                std::string final_text = "Nous avons la fonction f(x) = " + functions_input + " pour tout x appartenant à R.";
                final_text += " Nous pouvons la simplifier sous la forme f(x) = " + functions_input_simplify + ".</br></br>";
                // Study the variation of the function
                Function_Studied fs;
                fs.function_formula = polymonial;
                fs.function_name = "f";
                sequence_variation(fs, final_text);
                // Apply the redaction
                a_functions_redaction.get()->set_text(final_text);
                a_functions_redaction.get()->set_height_in_pixel(a_functions_redaction.get()->texture()->get_image()->height());
            }
        }
    }

    // Check the navigation event
    void Algebric_Solver_Page::check_navigation_events() {
        if(a_complex_number_navigation_button.get() != 0 && a_complex_number_navigation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_complex_number_page();
        if(a_function_navigation_button.get() != 0 && a_function_navigation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_function_page();
        if(a_home_navigation_button.get() != 0 && a_home_navigation_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_home_page();
        if(a_number_theory_button.get() != 0 && a_number_theory_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_number_theory_page();
        if(a_sequences_button.get() != 0 && a_sequences_button.get()->is_clicked_during_this_frame(GLFW_MOUSE_BUTTON_LEFT)) display_sequences_page();
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
    void Algebric_Solver_Page::display_number_theory_page() {
        hide_all();
        if(a_number_theory_page.get() != 0) a_number_theory_page.get()->set_visible(true);

        // Set the needed datas
        set_current_page(PLEOS_ALGEBRIC_SOLVER_NUMBER_THEORY_PAGE);
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
        if(a_number_theory_page.get() != 0) a_number_theory_page.get()->set_visible(false);
        if(a_sequences_page.get() != 0) a_sequences_page.get()->set_visible(false);

        // Clear the sequences part
        unload_sequences();
        a_sequences_analyse_recursions.get()->delete_children();
        a_sequences_analyse_recursions.get()->set_height_in_pixel(0);
    }
}
