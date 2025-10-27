#include "application.h"


int main(void)
{
  enum APP_EXIT_CODE app_exit_code = start_app();

  return app_exit_code;
}
