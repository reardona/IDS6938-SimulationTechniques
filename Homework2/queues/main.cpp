/*
  A simple program that simulates 5 MM1 queues at an airport. The first queue
  feeds 3 other queues that work in parallel. These feed a final queue.
  Simulation runs until error below threshold and, at the end,
  a performance evaluation report is shown, and logs are generated
  for plotting and analysis.
*/

using namespace std;

#include <random>
#include "customer.h"
#include "mm1_queue.h"


std::random_device rd;

void pause()
{
 std::string sInputString;
 // Wait for input from stdin (the keyboard)
 cout << "Continue (y)?";
 std::cin >> sInputString;
}



int main(int argc, char* argv[])
{
   int next = 0;
//   test_random_number_generator();

   for (int cur_lambda = 3; cur_lambda < 34; cur_lambda++)
   {
	   MM1_Queue    Checkin;
	   Checkin.set_file_names("01_log.txt", "01_wait.txt", "01_service.txt");
	   Checkin.set_lambda(cur_lambda);   // for this assignment this is set to a variable from the for loop.
	   Checkin.set_mu(53);
	   //Checkin.autogenerate_new_arrivals(false);
	   Checkin.initialize();
	   Checkin.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())
	  
	   MM1_Queue    Security1;
	  Security1.set_file_names("01_log.txt", "01_wait.txt", "01_service.txt");
	  Security1.set_lambda(cur_lambda);
	  Security1.set_mu(20);
	  Security1.autogenerate_new_arrivals(false);
	  Security1.initialize();
	  Security1.set_seed(rd(), rd());

	  MM1_Queue    Security2;
	  Security2.set_file_names("01_log.txt", "01_wait.txt", "01_service.txt");
	  Security2.set_lambda(cur_lambda);
	  Security2.set_mu(20);
	  Security2.autogenerate_new_arrivals(false);
	  Security2.initialize();
	  Security2.set_seed(rd(), rd());

	  MM1_Queue    Security3;
	  Security3.set_file_names("01_log.txt", "01_wait.txt", "01_service.txt");
	  Security3.set_lambda(cur_lambda);
	  Security3.set_mu(20);
	  Security3.autogenerate_new_arrivals(false);
	  Security3.initialize();
	  Security3.set_seed(rd(), rd());

	  MM1_Queue    Boarding;
	  Boarding.set_file_names("01_log.txt", "01_wait.txt", "01_service.txt");
	  Boarding.set_lambda(cur_lambda);
	  Boarding.set_mu(80);
	  Boarding.autogenerate_new_arrivals(false);
	  Boarding.initialize();
	  Boarding.set_seed(rd(), rd());

														
	
	//TODO Create MM1_Queue objects to capture the airport senario.

	   //************************************************************


   for (; 
		!Checkin.is_within_error_range(0.006) ||
	   !Security1.is_within_error_range(0.006) ||
	   !Security2.is_within_error_range(0.006) ||
	   !Security3.is_within_error_range(0.006) ||
	   !Boarding.is_within_error_range(0.006) 
	   //TODO: add is_within_error_range check*/
       ;)
   {
	   Customer cust  ;   cust = Checkin.process_next_event();  // =  TODO: process next event;
	   Customer cust2  ;  cust2 = Security1.process_next_event();  // =  TODO: process next event;
	   Customer cust3  ;   cust3 = Security2.process_next_event(); // =  TODO: process next event;
	   Customer cust4  ;   cust4 = Security3.process_next_event(); // =  TODO: process next event;
	   Customer cust5;   cust5 = Boarding.process_next_event(); // =  TODO: process next event;
	   //TODO: one more process_next_event for the last object.

       if (cust.get_type() == Customer::COMPLETED())
       {
          switch(next)
          {
            case 0:
				//TODO add_external_arrival() for your security gates;
				Security1.add_external_arrival();
				
                 break;
            case 1:
				Security2.add_external_arrival();
				//TODO add_external_arrival() for your security gates;
                 break;
            case 2:
				Security3.add_external_arrival();
                //TODO add_external_arrival() for your security gates;
                 break;
          }
          next++;
          if (next%3==0) next = 0;
       }
       if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())
       {
		   Boarding.add_external_arrival();
		   //TODO add_external_arrival(); on your final boarding MM1_Queue object
       }
   }

   Checkin.get_current_time();
	   Checkin.plot_results_output();

	Security1.get_current_time();
	   Security1.plot_results_output();

	   Security2.get_current_time();
	   Security2.plot_results_output();

	   Security3.get_current_time();
	   Security3.plot_results_output();

	   Boarding.get_current_time();
	   Boarding.plot_results_output();


	   Checkin.output("CheckinOutput.txt"); cout << "*********" << endl;
	   Security1.output("Sec1.txt"); cout << "*********" << endl;
	   Security2.output("Sec2.txt"); cout << "*********" << endl;
	   Security3.output("Sec3.txt"); cout << "*********" << endl;
	   Boarding.output("Board.txt"); cout << "*********" << endl;

   //TODO Output statistics airport senario.



   //**************************************************************************



   }

   return(0);
}

