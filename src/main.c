#include "application.h"


int main(void)
{
  enum APP_EXIT_CODE app_exit_code = startapp();

  return app_exit_code;
}
