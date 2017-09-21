
#pragma once
	class Date
	{
	public:
		Date(); // default builder
		Date(int day, int month, int year); // parameter builder
		~Date(); // demolisher?

				 // getters
		int getDate();
		int getMonth();
		int getYear();

		//setters
		void setDate(int day);
		void setMonth(int month);
		void setYear(int year);

		void print();

		void addDay();
		int howManyDaysInMonth();

	private:
		int day_;
		int month_;
		int year_;
	};

