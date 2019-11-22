class Student {
private:
        char* name;
        int no;
        int year_of_studies;
public:

        Student(const char*);
        Student();
        ~Student();
        #ifdef COPY
        Student(const Student&);          /* Copy-Constructor */
        #endif

        #ifdef ASSIGN
        Student& operator=(const Student&);   /* Function-symbol '=' overload */
        #endif

        void set_name(const char*);
        void set_no(int);
        void set_year_of_studies(int);

        char* get_name() const;
        int get_no() const;
        int get_year_of_studies() const;
};
