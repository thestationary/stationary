<html>
<head><title>PHP Mail Sender</title></head>
<body>
<?php

/* Check if the form was submitted */
if (isset($_POST['submitted'])) {
    $errors = array(); // Create an Error Array


    /* Check to see if all fields have a value */
    if (empty($_POST['email'])) {
        $errors[] = 'Please Enter an Email.';
    }

    if (empty($_POST['subject'])) {
        $errors[] = 'Please Enter a Subject.';
    }


    if (empty($_POST['message'])) {
        $errors[] = 'Please Enter a Message.';
    }


    if (empty($errors)) {


        /* All form fields are automatically passed to the PHP script through the array $_POST. */
        $email         = $_POST['email'];
        $subject       = $_POST['subject'];
        $message       = $_POST['message'];
        $textinput     = $_POST['textinput'];
        $password      = $_POST['password'];
        $radioinput    = $_POST['radioinput'];
        $checkboxinput = $_POST['checkboxinput'];
        $selectinput   = $_POST['selectinput'];
        $optioninput   = $_POST['optioninput'];

        echo " Email: $email <br />";
        echo " Subject: $subject <br />";
        echo " Message: $message <br />";
        echo " Text Input: $textinput <br />";
        echo " Password Input: $password <br />";
        echo " Radio Input: $radioinput <br />";
        echo " Checkbox Input: $checkboxinput <br />";
        echo " Select Input: $selectinput <br />";
        echo " Option Input: $optioninput <br />";

        $message = 'Text Area: ' . $message . ' Text Input: ' . $textinput . ' Password Input: ' . $password . ' Radio Input: ' . $radioinput . ' Checkbox Input: ' . $checkboxinput . ' Select Input: ' . $selectinput . ' Option Input: ' . $optioninput;

        /* Sends the mail and outputs the "Thank you" string if the mail is successfully sent, or the error string otherwise. */
        mail($email, $subject, $message);

        echo "Message Sent, Thank you <br />";

        echo "<a href='javascript:history.back(1);'>Click Here to go Back to the Previous Page</a>";

    } else { // Report all errors

        echo '<h2>An Error Occured</h2>
      <p>The Following Error Occured: <br />';

        foreach ($errors as $msg) { // Show each Error
            echo " - $msg<br />\n";
        }
        echo "<a href='javascript:history.back(1);'>Click Here to go Back to the Previous Page</a>";
    }
} // Close the Post Submitted Check

?>
</body>
</html>
