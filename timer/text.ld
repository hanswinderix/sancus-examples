sllvm_pm_foo_text_start = .;
*(.sllvm.text.dispatch.foo)  /* Make sure the dispatcher is put first */
*(.sllvm.text.foo)
sllvm_pm_foo_text_end = .;
