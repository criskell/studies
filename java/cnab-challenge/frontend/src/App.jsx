import { useEffect, useState } from 'react';
import axios from 'axios';

import './App.css';

const FETCH_TRANSACTIONS_URL = import.meta.env.VITE_REACT_APP_FETCH_URL;
const UPLOAD_CNAB_URL = import.meta.env.VITE_REACT_APP_UPLOAD_URL;

function App() {
  const [transactionReports, setTransactionReports] = useState([]);
  const [file, setFile] = useState(null);
  const [error, setError] = useState(null);
  const [success, setSuccess] = useState(null);
  const [isLoading, setIsLoading] = useState(false);

  const fetchTransactions = async () => {
    try {
      setIsLoading(true);
      const response = await axios.get('http://localhost:8080/transactions');
      setTransactionReports(response.data);
    } catch (e) {
      console.error('Error while fetching transactions:', e);
    } finally {
      setIsLoading(false);
      setError(null);
      setSuccess(null);
    }
  };

  const handleFileChange = (e) => {
    setFile(e.target.files[0]);
    setSuccess(e.target.files[0].name);
  };

  const uploadFile = async () => {
    try {
      const formData = new FormData();

      formData.append('file', file);

      await axios.post('http://localhost:8080/cnab/upload', formData, {
        headers: {
          'Content-type': 'multipart/form-data',
        },
      });

      setError(null);
      setSuccess(response.data);
    } catch (e) {
      console.error('Error while uploading CNAB file:', e);
      setError(e.response.data);
    }
  };

  const formatCurrency = (value) => {
    const formattedValue = new Intl.NumberFormat('pt-BR', {
      style: 'currency',
      currency: 'BRL',
    }).format(parseFloat(value));

    return formattedValue;
  };

  useEffect(() => {
    fetchTransactions();
  }, []);

  return (
    <div className="p-4">
      <h1 className="text-2xl font-semibold mb-4">CNAB Importer</h1>

      {/* File Upload Form */}
      <div className="mb-8">
        <div className="flex items-center space-x-4">
          <label className="text-gray-600">
            <span className="bg-blue-500 hover:bg-blue-600 cursor-pointer text-white py-2 px-4 rounded-lg">
              Choose file
            </span>
            <input
              type="file"
              accept=".txt"
              className="hidden"
              onChange={handleFileChange}
            />
          </label>
          <button
            className="bg-blue-700 hover:bg-blue-800 text-white py-2 px-4 rounded-lg"
            onClick={uploadFile}
          >
            Upload File
          </button>
        </div>
      </div>

      {success && <p className="text-green-500 mt-2">{success}</p>}
      {error && <p className="text-red-500 mt-2">{error}</p>}

      <br />

      <button
        className="bg-gray-200 hover:bg-gray-300 text-gray-600 py-2 px-4 rounded-lg mb-4"
        onClick={fetchTransactions}
        disabled={isLoading}
      >
        <FontAwesomeIcon icon={faSync} spin={isLoading} className="mr-2" />
        {isLoading ? 'Atualizando...' : 'Atualizar Transações'}
      </button>

      <div className="p-4">
        <h2 className="text-2xl font-semibold mb-4">Transactions</h2>

        <ul className="bg-white shadow-md rounded-md p-4">
          {transactionReports.length === 0 ? (
            <p className="mb-4 text-gray-500 text-center">
              Sem transações disponíveis.
            </p>
          ) : (
            transactionReports.map((report, key) => (
              <li
                key={key}
                className="mb-4 p-4 border-b border-gray-300 flex flex-col"
              >
                <div className="flex justify-between items-center mb-2">
                  <div className="text-xl font-semibold">
                    {report.storeName}
                  </div>
                  <div
                    className={`${
                      parseFloat(report.total) >= 0
                        ? 'text-green-500'
                        : 'text-red-500'
                    } font-semibold`}
                  >
                    Total: {formatCurrency(parseFloat(report.total))}
                  </div>
                </div>

                <table className="table-auto w-full">
                  <thead>
                    <tr className="px-4 py-2">Cartão</tr>
                    <tr className="px-4 py-2">CPF</tr>
                    <tr className="px-4 py-2">Data</tr>
                    <tr className="px-4 py-2">Dono da loja</tr>
                    <tr className="px-4 py-2">Hora</tr>
                    <tr className="px-4 py-2">Nome da loja</tr>
                    <tr className="px-4 py-2">Tipo</tr>
                    <tr className="px-4 py-2">Valor</tr>
                  </thead>
                  <tbody>
                    {report.transactions.map((transaction, key) => (
                      <tr
                        key={key}
                        className={key % 2 === 0 ? 'bg-gray-100' : ''}
                      >
                        <td className="px-4 py-2">{transaction.card}</td>
                        <td className="px-4 py-2">{transaction.cpf}</td>
                        <td className="px-4 py-2">{transaction.date}</td>
                        <td className="px-4 py-2">{transaction.hour}</td>
                        <td className="px-4 py-2">{transaction.storeName}</td>
                        <td className="px-4 py-2">{transaction.type}</td>
                        <td className="px-4 py-2">
                          {formatCurrency(transaction.value)}
                        </td>
                      </tr>
                    ))}
                  </tbody>
                </table>
              </li>
            ))
          )}
        </ul>
      </div>
    </div>
  );
}

export default App;
