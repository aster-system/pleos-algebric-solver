//******************
//
// pleos_algebric_solver.h
//
//******************
// Presentation :
//
// PLEOS, by Aster System, is a project which aims education.
// By using the power of SCLS and other Aster System's tools, we created  this.
// We want to make education easier for everyone (teachers, as students and pupils).
// The software is made in french, because the main goal is France educational system.
// For more information, see : https://aster-system.github.io/aster-system/projects/pleos.html.
//
// The "Algebric Solver" part aims mathematics lessons.
// Its goal is to solve a lot of communs problems quickly.
//
// This file contains the page of the Algebric Solver plugin.
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

#ifndef PLEOS_ALGEBRIC_SOLVER
#define PLEOS_ALGEBRIC_SOLVER

// Include PLEOS Libs
#include "../../pleos_libs/pleos_mathematics.h"

// Possibles pages
#define PLEOS_ALGEBRIC_SOLVER_COMPLEX_NUMBER_PAGE 0
#define PLEOS_ALGEBRIC_SOLVER_HOME_PAGE 1
#define PLEOS_ALGEBRIC_SOLVER_NUMBER_THEORY_PAGE 2
#define PLEOS_ALGEBRIC_SOLVER_FUNCTION_PAGE 3
#define PLEOS_ALGEBRIC_SOLVER_SEQUENCES_PAGE 4
#define PLEOS_ALGEBRIC_SOLVER_PROBABILITIES_PAGE 5
#define PLEOS_ALGEBRIC_SOLVER_MATRICES_PAGE 6

// The namespace "pleos" is used to simplify the all.
namespace pleos {

    class Algebric_Solver_Page : public scls::GUI_Page {
        // Class representating the algebric solver page for PLEOS
    public:

        // Analyse element
        struct __Function_Analyse_Element {

            #ifndef PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_IMAGE
            #define PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_IMAGE 0
            #endif // PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_IMAGE
            #ifndef PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_LIMIT
            #define PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_LIMIT 1
            #endif // PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_LIMIT
            #ifndef PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_DERIVATION
            #define PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_DERIVATION 2
            #endif // PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_DERIVATION

            // Type of element
            unsigned char type = PLEOS_ALGEBRIC_SOLVER_FUNCTION_ELEMENT_IMAGE;

            // GUI part of an element for a function analyse
            std::shared_ptr<scls::GUI_Text_Input> single_input;
            std::shared_ptr<scls::GUI_Object> parent;
            std::shared_ptr<scls::GUI_Text> title;
        };

        // Probability universe element
        struct __Probability_Universe_Element {

            #ifndef PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT
            #define PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT 0
            #endif // PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT
            #ifndef PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT_CONDITIONNAL
            #define PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT_CONDITIONNAL 1
            #endif // PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT_CONDITIONNAL

            // Type of element
            unsigned char type = PLEOS_ALGEBRIC_SOLVER_PROBABILITY_ELEMENT;

            // GUI part of an element for a function analyse
            std::shared_ptr<scls::GUI_Text_Input> condition_input;
            std::shared_ptr<scls::GUI_Text_Input> final_input;
            std::shared_ptr<scls::GUI_Text_Input> name_input;
            std::shared_ptr<scls::GUI_Object> parent;
            std::shared_ptr<scls::GUI_Text> title_1;
            std::shared_ptr<scls::GUI_Text> title_2;
            std::shared_ptr<scls::GUI_Text> title_final;
        };

        // Algebric_Solver_Page constructor
        Algebric_Solver_Page(scls::_Window_Advanced_Struct* window_struct, std::string name);
        // Loads an object in a page from XML
        virtual std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_complex_number(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_functions(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_home(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_matrices(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_navigation(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_number_theory(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_probabilities(std::string object_name, std::string object_type, scls::GUI_Object* parent);
        std::shared_ptr<scls::GUI_Object> __create_loaded_object_from_type_sequences(std::string object_name, std::string object_type, scls::GUI_Object* parent);

        //******************
        //
        // Complex number handling
        //
        //******************

        // Returns the current text to simplify
        inline std::string complex_number_simplify_input() const {if(a_complex_number_simplify_input.get() == 0) return std::string(); return a_complex_number_simplify_input.get()->text();};

        //******************
        //
        // Functions handling
        //
        //******************

        // Returns the current text to analyse
        inline std::string functions_analyse_input() const {if(a_functions_analyse_input.get() == 0) return std::string(); return a_functions_analyse_input.get()->text();};
        // Converts a string to a polymonial with functions datas
        scls::Formula functions_string_to_formula();
        // Loads an image finder in the elements
        __Function_Analyse_Element& load_function_analyse_element(unsigned char type);
        // Loads a derivation finder in the elements
        void load_function_analyse_derivation_finder();
        // Loads a derivation number finder in the elements
        void load_function_analyse_derivation_number_finder();
        // Loads an image finder in the elements
        void load_function_analyse_image_finder();
        // Loads a limit finder in the elements
        void load_function_analyse_limit_finder();
        // Places the elements in the functions analyse scroller
        inline void place_functions_analyse_elements() {
            if(a_functions_analyse_elements_content.size()>0) {
                a_functions_analyse_elements_content[0].parent.get()->attach_bottom_in_parent();
            } for(int i = 1;i<static_cast<int>(a_functions_analyse_elements_content.size());i++) {
                a_functions_analyse_elements_content[i].parent.get()->attach_top_of_object_in_parent(a_functions_analyse_elements_content[i - 1].parent.get());
            } a_functions_analyse_elements.get()->check_scroller();
        };
        // Unloads the functions analyse elements
        inline void unload_functions_analyse_elements(){a_functions_analyse_elements.get()->reset();a_functions_analyse_elements_content.clear();};

        //******************
        //
        // Matrices handling
        //
        //******************

        // Adds a matrice
        void add_matrice();
        // Calculates the matrices
        void calculate_matrice();
        // Places the matrice elements
        inline void place_matrices_elements() {
            if(a_matrices_elements.size()>0) {
                a_matrices_elements[a_matrices_elements.size() - 1].get()->attach_bottom_in_parent();
            } for(int i = 1;i<static_cast<int>(a_matrices_elements.size());i++) {
                int current_i = (a_matrices_elements.size() - 1) - i;
                a_matrices_elements[current_i].get()->attach_top_of_object_in_parent(a_matrices_elements[current_i + 1].get());
            } a_matrices.get()->check_scroller();
        };
        // Unloads the matrices elements
        inline void unload_matrices_elements(){a_matrices_elements.clear();a_matrices.get()->reset();};

        //******************
        //
        // Number theory
        //
        //******************

        // Generate a congruence circle
        void generate_congruence_circle();

        //******************
        //
        // Probabilities handling
        //
        //******************

        // Add the base of a simple element in the universe
        __Probability_Universe_Element& __add_universe_element(unsigned char type);
        // Add a simple element in the universe
        void add_probabilities_universe_element();
        // Add a conditionnal element in the elements
        void add_probabilities_universe_element_conditionnal();
        // Place the elements in the functions analyse scroller
        inline void place_probabilities_universe_elements() {
            if(a_probabilities_universe_elements.size()>0) {
                a_probabilities_universe_elements[a_probabilities_universe_elements.size()-1].parent.get()->attach_bottom_in_parent();
            } for(int i = 1;i<static_cast<int>(a_probabilities_universe_elements.size());i++) {
                int current_i = a_probabilities_universe_elements.size()-(i+1);
                a_probabilities_universe_elements[current_i].parent.get()->attach_top_of_object_in_parent(a_probabilities_universe_elements[current_i + 1].parent.get());
            } a_probabilities_universe.get()->check_scroller();
        };
        // Unloads the probabilities univer
        inline void unload_probabilities_universe(){a_probabilities_universe.get()->reset();a_probabilities_universe_elements.clear();};

        //******************
        //
        // Sequences handling
        //
        //******************

        // Adds a recursion to the sequence
        void sequences_add_recursion();
        // Convert a string to a polymonial with sequences datas
        scls::Formula sequences_string_to_polymonial();
        // Unload the recursions in the sequences
        inline void unload_sequences(){a_sequences_analyse_recursions_indices.clear();a_sequences_analyse_recursions_titles.clear();a_sequences_analyse_recursions_values.clear();};

        // Returns the current text to analyse
        inline std::string sequences_analyse_input() const {if(a_sequences_analyse_input.get() == 0) return std::string(); return a_sequences_analyse_input.get()->text();};
        // Update the title of the sequences
        inline void update_sequences_title() {if(a_sequences_analyse_recursions_titles.size() <= 0) {a_sequences_analyse_input_start.get()->set_text("s(n) = ");} else {a_sequences_analyse_input_start.get()->set_text("s(n + " + std::to_string(a_sequences_analyse_recursions_titles.size()) + ") = ");}};

        //******************
        //
        // Check the events
        //
        //******************

        // Check the complex number events
        void check_complex_number_events();
        // Check the functions events
        void check_functions_events();
        // Check the matrices events
        void check_matrices_events();
        // Check the navigation events
        void check_navigation_events();
        // Check the number theory events
        void check_number_theory_events();
        // Check the probabilities events
        void check_probabilities_events();
        // Check the sequences events
        void check_sequences_events();
        // Update the events
        virtual void update_event();

        //******************
        //
        // Handle the pages
        //
        //******************

        // Displays the complex number page
        void display_complex_number_page();
        // Displays the function page
        void display_function_page();
        // Displays the home page
        void display_home_page();
        // Displays the matrices page
        void display_matrices_page();
        // Displays the number theory page
        void display_number_theory_page();
        // Displays the probabilities page
        void display_probabilities_page();
        // Displays the sequences page
        void display_sequences_page();
        // Hides all the pages
        void hide_all();

        // Returns / resets the current page
        inline double current_number_theory_congruence_circle_modulo() const {return a_current_state.current_modulo;};
        inline unsigned short current_page() const {return a_current_state.current_page;};
        inline double current_number_theory_congruence_circle_point_number() const {return a_current_state.current_point_number;};
        inline void set_current_number_theory_congruence_circle_modulo(double new_current_number_theory_congruence_circle_modulo) {a_current_state.current_modulo = new_current_number_theory_congruence_circle_modulo;};
        inline void set_current_page(unsigned short new_page) {a_current_state.current_page = new_page;};
        inline void set_current_number_theory_congruence_circle_point_number(double new_current_number_theory_congruence_circle_point_number) {a_current_state.current_point_number = new_current_number_theory_congruence_circle_point_number;};

    private:

        // Current state of the page
        struct {
            // Current page
            unsigned short current_page = PLEOS_ALGEBRIC_SOLVER_HOME_PAGE;

            // Datas about the congruence circle
            double current_modulo = 2;
            double current_point_number = 10;
        } a_current_state;

        //******************
        //
        // GUI stuff
        //
        //******************

        // Set the redaction of a specific part
        inline void set_redaction(std::shared_ptr<scls::GUI_Text> redaction, std::string content) {redaction.get()->set_text(content);redaction.get()->set_height_in_pixel(redaction.get()->texture()->get_image()->height());};

        // Navigation button
        std::shared_ptr<scls::GUI_Text> a_complex_number_navigation_button;
        std::shared_ptr<scls::GUI_Text> a_function_navigation_button;
        std::shared_ptr<scls::GUI_Text> a_home_navigation_button;
        std::shared_ptr<scls::GUI_Text> a_matrices_button;
        std::shared_ptr<scls::GUI_Text> a_number_theory_button;
        std::shared_ptr<scls::GUI_Text> a_probabilities_button;
        std::shared_ptr<scls::GUI_Text> a_sequences_button;

        // Pages
        std::shared_ptr<scls::GUI_Object> a_complex_number_page;
        std::shared_ptr<scls::GUI_Object> a_functions_page;
        std::shared_ptr<scls::GUI_Object> a_home_page;
        std::shared_ptr<scls::GUI_Object> a_matrices_page;
        std::shared_ptr<scls::GUI_Object> a_number_theory_page;
        std::shared_ptr<scls::GUI_Object> a_probabilities_page;
        std::shared_ptr<scls::GUI_Object> a_sequences_page;

        // Complex number page
        // Simplification part
        std::shared_ptr<scls::GUI_Text> a_complex_number_simplify_button;
        std::shared_ptr<scls::GUI_Text_Input> a_complex_number_simplify_input;
        std::shared_ptr<scls::GUI_Text> a_complex_number_simplify_result;

        // Functions page
        std::shared_ptr<scls::GUI_Text> a_functions_redaction;
        // Analyse part
        std::shared_ptr<scls::GUI_Text> a_functions_analyse_button;
        std::shared_ptr<scls::GUI_Text_Input> a_functions_analyse_input;
        std::shared_ptr<scls::GUI_Scroller> a_functions_analyse_elements;
        std::vector<__Function_Analyse_Element> a_functions_analyse_elements_content;
        std::shared_ptr<scls::GUI_Text> a_functions_analyse_elements_derivation_button;
        std::shared_ptr<scls::GUI_Text> a_functions_analyse_elements_derivation_number_button;
        std::shared_ptr<scls::GUI_Text> a_functions_analyse_elements_limit_button;
        std::shared_ptr<scls::GUI_Text> a_functions_analyse_elements_value_button;

        // Matrices page
        std::shared_ptr<scls::GUI_Scroller> a_matrices;
        std::shared_ptr<scls::GUI_Text> a_matrices_add;
        std::shared_ptr<scls::GUI_Text> a_matrices_calculus;
        std::shared_ptr<scls::GUI_Text_Input> a_matrices_calculus_input;
        std::vector<std::shared_ptr<Matrice_GUI<scls::Fraction>>> a_matrices_elements;

        // Number theory
        std::shared_ptr<scls::GUI_Object> a_number_theory_congruence_circle;

        // Probabilities page
        std::shared_ptr<scls::GUI_Text> a_probabilities_redaction;
        // Tree handling
        std::shared_ptr<scls::GUI_Text> a_probabilities_tree_create;
        // Universe creation part
        std::shared_ptr<scls::GUI_Scroller> a_probabilities_universe;
        std::vector<__Probability_Universe_Element> a_probabilities_universe_elements;
        std::shared_ptr<scls::GUI_Text> a_probabilities_universe_add_element;
        std::shared_ptr<scls::GUI_Text> a_probabilities_universe_add_element_conditionnal;

        // Sequences page
        std::shared_ptr<scls::GUI_Text> a_sequences_redaction;
        // Analyse part
        std::shared_ptr<scls::GUI_Text> a_sequences_analyse_add_recursion_button;
        std::shared_ptr<scls::GUI_Text> a_sequences_analyse_button;
        std::shared_ptr<scls::GUI_Text_Input> a_sequences_analyse_input;
        std::shared_ptr<scls::GUI_Text> a_sequences_analyse_input_start;
        std::shared_ptr<scls::GUI_Object> a_sequences_analyse_recursions;
        std::vector<std::shared_ptr<scls::GUI_Text_Input>> a_sequences_analyse_recursions_indices;
        std::vector<std::shared_ptr<scls::GUI_Text>> a_sequences_analyse_recursions_titles;
        std::vector<std::shared_ptr<scls::GUI_Text_Input>> a_sequences_analyse_recursions_values;
    };

    class __Temp_Pleos_Window : public scls::Window {
        // Temporary used window by PLEOS
    public :
        // __Temp_Pleos_Window constructor
        __Temp_Pleos_Window(unsigned int w, unsigned int h, std::string path) : scls::Window(w, h, path) { set_window_title("PLEOS - Solveur algébrique"); }

        // Create an object in the window
        std::shared_ptr<scls::Object> __create_loaded_object_from_type(std::string object_name, std::string object_type) {
            if(object_name == "algebric_solver") {
                std::shared_ptr<Algebric_Solver_Page> hub = *new_page_2d<Algebric_Solver_Page>(object_name);

                // Return the good object
                std::shared_ptr<scls::Object> to_return = hub;
                return to_return;
            } return scls::Window::__create_loaded_object_from_type(object_name, object_type);
        }
    };
}

#endif // PLEOS_ALGEBRIC_SOLVER
