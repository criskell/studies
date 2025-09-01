import { useEffect, useState } from 'react';

import './App.css';

function App() {
  const [transactionReports, setTransactions] = useState();
  const [file, setFile] = useState(null);

  const fetchTransactions = async () => {
    const response = await axios.get('http://localhost:8080/transactions');

    setTransactions(response.data);
  };

  const handleFileChange = (e) => {
    setFile(e.target.files[0]);
  };

  const uploadFile = async () => {
    const formData = new FormData();

    formData.append('file', file);

    await axios.post('http://localhost:8080', formData, {
      headers: {
        'Content-type': 'multipart/form-data',
      },
    });
  };

  useEffect(() => {
    fetchTransactions();
  }, []);

  return (
    <>
      <div>
        <h1>Importação de CNAB</h1>
      </div>

      <div>
        <span>Choose file</span>
        <input type="file" accept=".txt" onChange={handleFileChange} />
        <button onClick={uploadFile}>Upload File</button>
      </div>

      <div>
        <h2>Transactions</h2>

        <ul>
          {transactionReports.map((report, key) => (
            <li>
              <table>
                <thead>
                  <tr>Cartão</tr>
                  <tr>CPF</tr>
                  <tr>Data</tr>
                  <tr>Dono da loja</tr>
                  <tr>Hora</tr>
                  <tr>Nome da loja</tr>
                  <tr>Tipo</tr>
                  <tr>Valor</tr>
                </thead>
                <tbody>
                  {report.transactions.map((transaction, key) => (
                    <tr
                      key={key}
                      className={idx % 2 === 0 ? 'bg-gray-100' : 'bg-white'}
                    >
                      <td className="px-4 py-2">{transaction.card}</td>
                      <td className="px-4 py-2">{transaction.cpf}</td>
                      <td className="px-4 py-2">{transaction.date}</td>
                      <td className="px-4 py-2">{transaction.hour}</td>
                      <td className="px-4 py-2">{transaction.storeName}</td>
                      <td className="px-4 py-2">{transaction.type}</td>
                      <td className="px-4 py-2">{transaction.value}</td>
                    </tr>
                  ))}
                </tbody>
              </table>
            </li>
          ))}
        </ul>
      </div>
    </>
  );
}

export default App;
