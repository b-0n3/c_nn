#include "stringbuilder.h"
#include "test_tools.h"


t_string_builder *sb;
const char *TEST_FINAL_PHRASE = "test 12.09 testappend testappendformated 11";

void test_init_str(){
   jmp_buf * __TRY_CATCH_LIB__raise_env =NULL;
// used by macros for RETRY
 jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;
  t_string_builder *builder;
  int exception;
  builder = new_string_builder("test");
  assert_eq(builder == NULL, 0);
  builder->free(builder);
  TRY(
    builder = new_string_builder(NULL);
    THROW(TEST_FAILED_EXCEPTION, "TEST INIT STR ON NULL POINTER FAILED");
  )CATCH(exception > 0,
    print_test_passed("init");
  );
}

void test_inti_args()
{
  jmp_buf * __TRY_CATCH_LIB__raise_env =NULL;
// used by macros for RETRY
 jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;
  t_string_builder *test;
  int exception = -1;
  sb = new_string_builder_formated("%s %.2f ","test", 12.09);
   TRY(
    test = new_string_builder(NULL);
    THROW(TEST_FAILED_EXCEPTION, "TEST INIT formated ON NULL POINTER FAILED");
  )CATCH(exception !=  TEST_FAILED_EXCEPTION,
    printf("dsf");
  );
}

void test_append()
{
  int exception = -1;
  jmp_buf * __TRY_CATCH_LIB__raise_env =NULL;
// used by macros for RETRY
 jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;

  assert_eq(sb != NULL, 1);
  sb->append(sb, "testappend ");
   TRY(
    sb->append(NULL, "testappend");
    THROW(TEST_FAILED_EXCEPTION, "TEST append  ON NULL POINTER FAILED");
  )CATCH(exception !=  TEST_FAILED_EXCEPTION,
    printf("sdf");
  );

}

void test_append_formated()
{
  int exception = -1;
  jmp_buf * __TRY_CATCH_LIB__raise_env =NULL;
// used by macros for RETRY
 jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;

  assert_eq(sb != NULL,  1);
  sb->append_formated(sb, "%s %d ", "test_append_formated", 11);
   TRY(
    sb->append_formated(NULL, "testappend");
    THROW(TEST_FAILED_EXCEPTION, "TEST append__formated  ON NULL POINTER FAILED");
  )CATCH(exception !=  TEST_FAILED_EXCEPTION,
    printf(" ");
  );
  printf("{%s}\n",sb->to_string(sb));
}

void test_to_string()
{
  char *line;
  int exception = -1;
  jmp_buf * __TRY_CATCH_LIB__raise_env =NULL;
// used by macros for RETRY
 jmp_buf * __TRY_CATCH_LIB__retry_env = NULL;

  assert_eq(sb != NULL, 1);
  line = sb->to_string(sb);
  printf("liasdfasdfasdfne = {%s}\n", line);
  assert_eq(line != NULL , 1);
  assert_eq(strcmp(line, TEST_FINAL_PHRASE), 0);
  TRY(
    sb->to_string(NULL);
    THROW(TEST_FAILED_EXCEPTION, "TEST append__formated  ON NULL POINTER FAILED");
  )CATCH(exception ==  TEST_FAILED_EXCEPTION,
    printf("line = {%s}\n", line);
  );
  
}

void test_free(){
  sb->free(sb);
}

void main()
{
  print_sp_line("test init str");
  test_init_str();
  print_sp_line("test_init_args");
  test_inti_args();
  print_sp_line("test append");
  test_append();
  print_sp_line("test append formated");
  test_append_formated();
  print_sp_line("test to string");
  test_to_string();
  print_sp_line("test free");
  test_free();
}