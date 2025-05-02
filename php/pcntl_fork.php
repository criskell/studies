<?php

$pid = pcntl_fork();

if ($pid == 0) {
	echo "[FILHO] Estamos dentro do processo filho.\n";
	echo "[FILHO] Meu PID:" . getmypid() . "\n";
	sleep(2);
	echo "[FILHO] Terminei os trabalhos.\n";
	exit(-1);
}

if ($pid == -1) {
	echo "[PAI] Não foi possível criar o processo filho.\n";
	exit(-1);
}

if ($pid > 0) {
	echo "[PAI] PID do processo pai: " . getmypid() . "\n";
	echo "[PAI] Processo filho criado com PID " . $pid . "\n";
}

echo "[PID] Código depois do fork.\n";

pcntl_waitpid($pid, $status);

// Verifica se o processo filho terminou normalmente.
if (pcntl_wifexited($status)) {
	echo "[PAI] O processo filho terminou normalmente.\n";
	echo "[PAI] O filho retornou o código: " . pcntl_wexitstatus($status) . "\n";
}

if (pcntl_wifsignaled($status)) {
	echo "[PAI] O processo filho terminou por causa de um signal.\n";
	echo "[PAI] Código do sinal é " . pcntl_wtermsig($status) . "\n";
}
