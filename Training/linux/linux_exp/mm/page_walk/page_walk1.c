long myioctl(struct file *fp, unsigned int pid, unsigned long gvar)
{
	struct task_struct *my_task = current;
	pgd_t *pgd = my_task -> mm -> pgd;	//PGD base virtual address
	pte_t *ptep, pte;
	unsigned int address;

	address = (gvar >> 22);

	pgd = pgd_offset(pgd, address);
	if (pgd_none(*pgd) || pgd_bad(*pgd))
		return 0;

	address = ((gvar << 10) >> 22);

//	pmd = pmd_offset(pgd, address);
//	if (pmd_none(*pmd) || pmd_bad(*pmd))
//		goto out;

	ptep = pte_offset(pgd, address);
	if (!ptep)
		return 0;

	pte = *ptep;

	return 0;
}
